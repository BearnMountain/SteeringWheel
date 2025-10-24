cmake_minimum_required(VERSION 3.13)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Toolchain setup BEFORE project()
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR ARM)

set(ARM_TOOLCHAIN_PATH "/Applications/ArmGNUToolchain/14.3.rel1/arm-none-eabi/bin")
set(CMAKE_C_COMPILER ${ARM_TOOLCHAIN_PATH}/arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER ${ARM_TOOLCHAIN_PATH}/arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER ${ARM_TOOLCHAIN_PATH}/arm-none-eabi-gcc)
set(CMAKE_AR ${ARM_TOOLCHAIN_PATH}/arm-none-eabi-ar)
set(CMAKE_OBJCOPY ${ARM_TOOLCHAIN_PATH}/arm-none-eabi-objcopy)
set(CMAKE_OBJDUMP ${ARM_TOOLCHAIN_PATH}/arm-none-eabi-objdump)
set(CMAKE_SIZE ${ARM_TOOLCHAIN_PATH}/arm-none-eabi-size)

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

project(motor_mcu C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Fetch STM32CubeF4
include(FetchContent)
FetchContent_Declare(
    stm32cubef4
    GIT_REPOSITORY https://github.com/STMicroelectronics/STM32CubeF4.git
    GIT_TAG v1.28.1
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(stm32cubef4)
set(STM32CUBE_DIR ${stm32cubef4_SOURCE_DIR})

# MCU flags
set(MCU_FLAGS "-mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard")

add_compile_definitions(STM32F407xx USE_HAL_DRIVER)

set(CMAKE_C_FLAGS "${MCU_FLAGS} -Wall -fdata-sections -ffunction-sections")
set(CMAKE_C_FLAGS_DEBUG "-Og -g3")
set(CMAKE_C_FLAGS_RELEASE "-O3")

# Linker script
set(LINKER_SCRIPT "${STM32CUBE_DIR}/Projects/STM32F4-Discovery/Templates_LL/STM32CubeIDE/STM32F407VGTX_FLASH.ld")

set(CMAKE_EXE_LINKER_FLAGS "${MCU_FLAGS} -T${LINKER_SCRIPT} \
    -Wl,-Map=motor_mcu.map,--cref \
    -Wl,--gc-sections \
	-Wl,--no-warn-rwx-segments \
    -specs=nano.specs \
    -lc -lm \
	-Wl,--no-warn-rwx-segments"
)

# Sources
file(GLOB_RECURSE APP_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.c")
file(GLOB HAL_SOURCES "${STM32CUBE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/*.c")
list(FILTER HAL_SOURCES EXCLUDE REGEX ".*_template\\.c$")

set(STARTUP_FILE "${STM32CUBE_DIR}/Drivers/CMSIS/Device/ST/STM32F4xx/Source/Templates/gcc/startup_stm32f407xx.s")
set(SYSTEM_FILE "${STM32CUBE_DIR}/Drivers/CMSIS/Device/ST/STM32F4xx/Source/Templates/system_stm32f4xx.c")

add_executable(motor_mcu.elf
    ${APP_SOURCES}
    ${HAL_SOURCES}
    ${STARTUP_FILE}
    ${SYSTEM_FILE}
)

target_include_directories(motor_mcu.elf PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/inc
    ${STM32CUBE_DIR}/Drivers/CMSIS/Include
    ${STM32CUBE_DIR}/Drivers/CMSIS/Device/ST/STM32F4xx/Include
    ${STM32CUBE_DIR}/Drivers/STM32F4xx_HAL_Driver/Inc
)

target_compile_definitions(motor_mcu.elf PRIVATE
    STM32F4
    STM32F407xx  # or your specific chip
)

add_custom_command(TARGET motor_mcu.elf POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:motor_mcu.elf> motor_mcu.hex
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:motor_mcu.elf> motor_mcu.bin
    COMMAND ${CMAKE_SIZE} $<TARGET_FILE:motor_mcu.elf>
)
