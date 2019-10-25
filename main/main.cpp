#include <stdio.h>

/* esp core */
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"

#include "esp_system.h"
#include "esp_spi_flash.h"
#include "esp32/spiram.h"
#include "esp32/himem.h"

#include "tensorflow/lite/c/c_api_internal.h"
#include "tensorflow/lite/experimental/micro/kernels/micro_ops.h"
#include "tensorflow/lite/experimental/micro/micro_error_reporter.h"
#include "tensorflow/lite/experimental/micro/micro_interpreter.h"
#include "tensorflow/lite/experimental/micro/micro_mutable_op_resolver.h"
#include "tensorflow/lite/schema/schema_generated.h"
#include "tensorflow/lite/version.h"

#include "model_settings.h"
#include "person_detect_model_data.h"

#include "esp32_camera.h"


extern "C" {
    namespace {
        tflite::ErrorReporter* error_reporter = nullptr;
        const tflite::Model* model = nullptr;
        tflite::MicroInterpreter* interpreter = nullptr;
        TfLiteTensor* input = nullptr;
        constexpr int kTensorArenaSize = 70 * 1024;
        static uint8_t tensor_arena[kTensorArenaSize];
    }  // namespace

    void setup() {
      static tflite::MicroErrorReporter micro_error_reporter;
      error_reporter = &micro_error_reporter;

      model = tflite::GetModel(g_person_detect_model_data);
      if (model->version() != TFLITE_SCHEMA_VERSION) {
        error_reporter->Report(
            "Model provided is schema version %d not equal "
            "to supported version %d.",
            model->version(), TFLITE_SCHEMA_VERSION);
      }

      static tflite::MicroMutableOpResolver micro_mutable_op_resolver;
      micro_mutable_op_resolver.AddBuiltin(
          tflite::BuiltinOperator_DEPTHWISE_CONV_2D,
          tflite::ops::micro::Register_DEPTHWISE_CONV_2D());
      micro_mutable_op_resolver.AddBuiltin(tflite::BuiltinOperator_CONV_2D,
                                           tflite::ops::micro::Register_CONV_2D());
      micro_mutable_op_resolver.AddBuiltin(
          tflite::BuiltinOperator_AVERAGE_POOL_2D,
          tflite::ops::micro::Register_AVERAGE_POOL_2D());

      static tflite::MicroInterpreter static_interpreter(
          model, micro_mutable_op_resolver, tensor_arena, kTensorArenaSize,
          error_reporter);
      interpreter = &static_interpreter;

      TfLiteStatus allocate_status = interpreter->AllocateTensors();
      if (allocate_status != kTfLiteOk) {
        error_reporter->Report("AllocateTensors() failed");
      }
      input = interpreter->input(0);
    }

    void loop() {
      if (kTfLiteOk != GetImage(error_reporter, kNumCols, kNumRows, kNumChannels,
                                input->data.uint8)) {
        error_reporter->Report("Image capture failed.");
      }

      if (kTfLiteOk != interpreter->Invoke()) {
        error_reporter->Report("Invoke failed.");
      }

      TfLiteTensor* output = interpreter->output(0);

      uint8_t person_score = output->data.uint8[kPersonIndex];
      uint8_t no_person_score = output->data.uint8[kNotAPersonIndex];
      printf("person: %d - no_person: %d \n", person_score, no_person_score);
    }

    void app_main(void) {
        setup();
        while(1){
            loop();
        }
    }
};
