#ifndef __STM32F4xx_HAL_CONF_H
#define __STM32F4xx_HAL_CONF_H
#ifdef __cplusplus
 extern "C" {
#endif

#define HAL_MODULE_ENABLED
#define HAL_CORTEX_MODULE_ENABLED
#define HAL_RCC_MODULE_ENABLED
#define HAL_GPIO_MODULE_ENABLED
#define HAL_FLASH_MODULE_ENABLED
#define HAL_PWR_MODULE_ENABLED
#define HAL_DMA_MODULE_ENABLED

// Clock values - MUST be defined BEFORE includes
#define HSE_VALUE             8000000U
#define HSI_VALUE             16000000U
#define LSI_VALUE             32000U
#define LSE_VALUE             32768U
#define VDD_VALUE             3300U
#define HSE_STARTUP_TIMEOUT   100U        // Must be before includes
#define LSE_STARTUP_TIMEOUT   5000U       // Must be before includes
#define EXTERNAL_CLOCK_VALUE  8000000U    // Must be before includes

#define TICK_INT_PRIORITY     0U
#define USE_RTOS              0U
#define PREFETCH_ENABLE       1U
#define INSTRUCTION_CACHE_ENABLE 1U
#define DATA_CACHE_ENABLE     1U
#define USE_FULL_ASSERT       0U

// Assert macro definition
#if USE_FULL_ASSERT
  #define assert_param(expr) ((expr) ? (void)0U : assert_failed((uint8_t *)__FILE__, __LINE__))
  void assert_failed(uint8_t *file, uint32_t line);
#else
  #define assert_param(expr) ((void)0U)
#endif

// Include HAL modules AFTER defining all values
#include "stm32f4xx_hal_rcc.h"
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal_dma.h"
#include "stm32f4xx_hal_cortex.h"
#include "stm32f4xx_hal_flash.h"
#include "stm32f4xx_hal_pwr.h"

#ifdef __cplusplus
}
#endif
#endif /* __STM32F4xx_HAL_CONF_H */
