# tf-esp32

a small component esp-idf for supporting tensorflow lite inferences for microcontrollers (experimental)

esp-idf:<br>
https://docs.espressif.com/projects/esp-idf/en/latest/

tensorflow lite microcontroller:<br>
https://www.tensorflow.org/lite/microcontrollers/overview

<br>

<ul>
<li>use tensorflow for training your model</li>
<li>convert model tensorflow in tflite quantization</li>
<li>convert tflite model to array c</li>
</ul>

<br>
main folder contain example tflite load model<br>
components folder contain tensorflow lite source and cmake structure<br>
<br>

```bash
tf-esp32/
├── CMakeLists.txt
├── components
│   ├── CMakeLists.txt
│   ├── component.mk
│   └── tf
│       ├── LICENSE
│       ├── tensorflow
│       │   └── lite
│       │       ├── c
│       │       │   ├── builtin_op_data.h
│       │       │   ├── c_api_internal.c
│       │       │   ├── c_api_internal.h
│       │       │   └── c_api_internal.o
│       │       ├── core
│       │       │   └── api
│       │       │       ├── error_reporter.cc
│       │       │       ├── error_reporter.h
│       │       │       ├── error_reporter.o
│       │       │       ├── flatbuffer_conversions.cc
│       │       │       ├── flatbuffer_conversions.h
│       │       │       ├── flatbuffer_conversions.o
│       │       │       ├── op_resolver.cc
│       │       │       ├── op_resolver.h
│       │       │       └── op_resolver.o
│       │       ├── experimental
│       │       │   └── micro
│       │       │       ├── compatibility.h
│       │       │       ├── debug_log.cc
│       │       │       ├── debug_log.h
│       │       │       ├── debug_log_numbers.cc
│       │       │       ├── debug_log_numbers.h
│       │       │       ├── debug_log_numbers.o
│       │       │       ├── debug_log.o
│       │       │       ├── kernels
│       │       │       │   ├── all_ops_resolver.cc
│       │       │       │   ├── all_ops_resolver.h
│       │       │       │   ├── all_ops_resolver.o
│       │       │       │   ├── depthwise_conv.cc
│       │       │       │   ├── depthwise_conv.o
│       │       │       │   ├── fully_connected.cc
│       │       │       │   ├── fully_connected.o
│       │       │       │   ├── fully_connected_test.cc
│       │       │       │   ├── fully_connected_test.o
│       │       │       │   ├── softmax.cc
│       │       │       │   └── softmax.o
│       │       │       ├── micro_error_reporter.cc
│       │       │       ├── micro_error_reporter.h
│       │       │       ├── micro_error_reporter.o
│       │       │       ├── micro_interpreter.cc
│       │       │       ├── micro_interpreter.h
│       │       │       ├── micro_interpreter.o
│       │       │       ├── micro_mutable_op_resolver.cc
│       │       │       ├── micro_mutable_op_resolver.h
│       │       │       ├── micro_mutable_op_resolver.o
│       │       │       ├── simple_tensor_allocator.cc
│       │       │       ├── simple_tensor_allocator.h
│       │       │       ├── simple_tensor_allocator.o
│       │       │       └── testing
│       │       │           ├── micro_test.h
│       │       │           └── test_utils.h
│       │       ├── kernels
│       │       │   ├── internal
│       │       │   │   ├── common.h
│       │       │   │   ├── compatibility.h
│       │       │   │   ├── quantization_util.cc
│       │       │   │   ├── quantization_util.h
│       │       │   │   ├── quantization_util.o
│       │       │   │   ├── reference
│       │       │   │   │   ├── depthwiseconv_float.h
│       │       │   │   │   ├── depthwiseconv_uint8.h
│       │       │   │   │   ├── fully_connected.h
│       │       │   │   │   └── softmax.h
│       │       │   │   ├── round.h
│       │       │   │   ├── tensor_ctypes.h
│       │       │   │   └── types.h
│       │       │   ├── kernel_util.cc
│       │       │   ├── kernel_util.h
│       │       │   ├── kernel_util.o
│       │       │   ├── op_macros.h
│       │       │   └── padding.h
│       │       ├── schema
│       │       │   └── schema_generated.h
│       │       └── version.h
│       └── third_party
│           ├── flatbuffers
│           │   ├── include
│           │   │   └── flatbuffers
│           │   │       ├── base.h
│           │   │       ├── flatbuffers.h
│           │   │       └── stl_emulation.h
│           │   └── LICENSE.txt
│           └── gemmlowp
│               ├── fixedpoint
│               │   ├── fixedpoint.h
│               │   └── fixedpoint_sse.h
│               ├── internal
│               │   └── detect_platform.h
│               └── LICENSE
├── main
│   ├── CMakeLists.txt
│   ├── component.mk
│   ├── main.cpp
│   └── model.h
├── README.md
├── sdkconfig
├── sdkconfig.ci
└── sdkconfig.old
```
