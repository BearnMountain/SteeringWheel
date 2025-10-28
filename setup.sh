#!/bin/bash
set -e

echo "Building Steering Wheel (Pico2)"
cmake -B build/pico -DBUILD_STEERING=ON -DPICO_BOARD=pico2 steering_src/
cmake --build build/pico -j4

# echo ""
# echo "Building Motor MCU (STM32F4)"
# cmake -B build/stm32 motor_src/
# cmake --build build/stm32 -j4

echo ""
echo "Build Complete!"
echo "Pico:  build/pico/steering_wheel.uf2"
# echo "STM32: build/stm32/motor_mcu.elf"
