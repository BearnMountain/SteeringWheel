cmake_minimum_required(VERSION 3.13)

# Delegates to subdirectories for  building
project(embedded_system)

# Build steering wheel (Pico)
if(BUILD_STEERING)
    add_subdirectory(steering_src)
endif()

# Build motor MCU (STM32)
if(BUILD_MOTOR)
    add_subdirectory(motor_src)
endif()
