#include "cam_config.h"

#define MAX_JPEG_BYTES 4096
uint8_t jpeg_buffer[MAX_JPEG_BYTES] = {0};
uint32_t jpeg_length = 0;

int init_camera(tflite::ErrorReporter* error_reporter) {
  error_reporter->Report("Attempting to start Arducam");

  vTaskDelay(100 / portTICK_PERIOD_MS);
  return 0;
}

// Begin the capture and wait for it to finish
int PerformCapture(tflite::ErrorReporter* error_reporter) {
    error_reporter->Report("Starting capture");
    return 0;
}

// Read data from the camera module into a local buffer
int ReadData(tflite::ErrorReporter* error_reporter) {
  if (jpeg_length == 0) {
    error_reporter->Report("No data buffer");
    return -1;
  }
  //delayMicroseconds(15);
  vTaskDelay(15);
  return 0;
}

// Decode the JPEG image, crop it, and convert it to greyscale
int DecodeAndProcessImage(tflite::ErrorReporter* error_reporter,
                                   int image_width, int image_height,
                                   uint8_t* image_data) {
  /*error_reporter->Report("Decoding JPEG and converting to greyscale");
  // Parse the JPEG headers. The image will be decoded as a sequence of Minimum
  // Coded Units (MCUs), which are 16x8 blocks of pixels.
  JpegDec.decodeArray(jpeg_buffer, jpeg_length);

  // Crop the image by keeping a certain number of MCUs in each dimension
  const int keep_x_mcus = image_width / JpegDec.MCUWidth;
  const int keep_y_mcus = image_height / JpegDec.MCUHeight;

  // Calculate how many MCUs we will throw away on the x axis
  const int skip_x_mcus = JpegDec.MCUSPerRow - keep_x_mcus;
  // Roughly center the crop by skipping half the throwaway MCUs at the
  // beginning of each row
  const int skip_start_x_mcus = skip_x_mcus / 2;
  // Index where we will start throwing away MCUs after the data
  const int skip_end_x_mcu_index = skip_start_x_mcus + keep_x_mcus;
  // Same approach for the columns
  const int skip_y_mcus = JpegDec.MCUSPerCol - keep_y_mcus;
  const int skip_start_y_mcus = skip_y_mcus / 2;
  const int skip_end_y_mcu_index = skip_start_y_mcus + keep_y_mcus;

  // Pointer to the current pixel
  uint16_t* pImg;
  // Color of the current pixel
  uint16_t color;

  // Loop over the MCUs
  while (JpegDec.read()) {
    // Skip over the initial set of rows
    if (JpegDec.MCUy < skip_start_y_mcus) {
      continue;
    }
    // Skip if we're on a column that we don't want
    if (JpegDec.MCUx < skip_start_x_mcus ||
        JpegDec.MCUx >= skip_end_x_mcu_index) {
      continue;
    }
    // Skip if we've got all the rows we want
    if (JpegDec.MCUy >= skip_end_y_mcu_index) {
      continue;
    }
    // Pointer to the current pixel
    pImg = JpegDec.pImage;

    // The x and y indexes of the current MCU, ignoring the MCUs we skip
    int relative_mcu_x = JpegDec.MCUx - skip_start_x_mcus;
    int relative_mcu_y = JpegDec.MCUy - skip_start_y_mcus;

    // The coordinates of the top left of this MCU when applied to the output
    // image
    int x_origin = relative_mcu_x * JpegDec.MCUWidth;
    int y_origin = relative_mcu_y * JpegDec.MCUHeight;

    // Loop through the MCU's rows and columns
    for (int mcu_row = 0; mcu_row < JpegDec.MCUHeight; mcu_row++) {
      // The y coordinate of this pixel in the output index
      int current_y = y_origin + mcu_row;
      for (int mcu_col = 0; mcu_col < JpegDec.MCUWidth; mcu_col++) {
        // Read the color of the pixel as 16-bit integer
        color = *pImg++;
        // Extract the color values (5 red bits, 6 green, 5 blue)
        uint8_t r, g, b;
        r = ((color & 0xF800) >> 11) * 8;
        g = ((color & 0x07E0) >> 5) * 4;
        b = ((color & 0x001F) >> 0) * 8;
        // Convert to grayscale by calculating luminance
        // See https://en.wikipedia.org/wiki/Grayscale for magic numbers
        float gray_value = (0.2126 * r) + (0.7152 * g) + (0.0722 * b);

        // The x coordinate of this pixel in the output image
        int current_x = x_origin + mcu_col;
        // The index of this pixel in our flat output buffer
        int index = (current_y * image_width) + current_x;
        image_data[index] = static_cast<uint8_t>(gray_value);
      }
    }
  }
  error_reporter->Report("Image decoded and processed");*/
  return 0;
}

// Get an image from the camera module
int GetImage(tflite::ErrorReporter* error_reporter, int image_width,
                      int image_height, int channels, uint8_t* image_data) {
  /*static bool g_is_camera_initialized = false;
  if (!g_is_camera_initialized) {
    TfLiteStatus init_status = InitCamera(error_reporter);
    if (init_status != kTfLiteOk) {
      error_reporter->Report("InitCamera failed");
      return init_status;
    }
    g_is_camera_initialized = true;
  }

  TfLiteStatus capture_status = PerformCapture(error_reporter);
  if (capture_status != kTfLiteOk) {
    error_reporter->Report("PerformCapture failed");
    return capture_status;
  }

  TfLiteStatus read_data_status = ReadData(error_reporter);
  if (read_data_status != kTfLiteOk) {
    error_reporter->Report("ReadData failed");
    return read_data_status;
  }

  TfLiteStatus decode_status = DecodeAndProcessImage(
      error_reporter, image_width, image_height, image_data);
  if (decode_status != kTfLiteOk) {
    error_reporter->Report("DecodeAndProcessImage failed");
    return decode_status;
  }*/

  return 0;
}
