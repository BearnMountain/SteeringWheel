cmake_minimum_required(VERSION 3.13)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Pull in Pico SDK
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

# IMPORTANT: add ASM here
project(steering_wheel C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the Pico SDK
pico_sdk_init()

add_executable(steering_wheel 
	src/main.c
)

pico_enable_stdio_usb(steering_wheel 1)
pico_enable_stdio_uart(steering_wheel 0)

target_link_libraries(steering_wheel pico_stdlib hardware_gpio)

pico_add_extra_outputs(steering_wheel)

