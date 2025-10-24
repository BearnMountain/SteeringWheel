#ifndef __MCU_H
#define __MCU_H

void SystemClock_Config(); // 170MHz for STM32G4
void GPIO_Init();
void SPI_Init(); // encoder out
void ADC_Init(); // current sensing
void TIM_PWM_Init(); // 6-channel pwm 
void TIM_ADC_Trigger_Init(); // sync adc with pwm

#endif
