cmake_minimum_required(VERSION 3.13)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Pull in Pico SDK
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(steering_wheel C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(steering_wheel 
    main.c
    usb_descriptors.c
)

target_include_directories(steering_wheel PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

pico_enable_stdio_usb(steering_wheel 0)
pico_enable_stdio_uart(steering_wheel 1)

target_link_libraries(steering_wheel 
    pico_stdlib 
    hardware_adc
    hardware_gpio
    tinyusb_device
    tinyusb_board
)

pico_add_extra_outputs(steering_wheel)
