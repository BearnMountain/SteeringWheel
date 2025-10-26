#include "stm32g4xx_hal.h"
#include "mcu/mcu.h"


int main(void) {
	// HAL_Init();
	// SystemClock_Config(); // 170MHz for STM32G4

	// // Peripherals
	// GPIO_Init();
	// SPI_Init(); // encoder out
	// ADC_Init(); // current sensing
	// TIM_PWM_Init(); // 6-channel pwm 
	// TIM_ADC_Trigger_Init(); // sync adc with pwm
	
	// Encoder Setup
	// AS5147_Init();
	// AS5147_CheckConnection();
	//
	// // Motor Params
	// Motor_SetParameter();
	//
	// // Calibration
	// Calibrate_CurrentSensors();
	// Calibrate_EncoderOffset();
	//
	// // Control Loop
	// FOC_Init();
	// Enable_PWM_Outputs();
	// Start_Control_Loop_Timer();
	//
	// // Main Loop
	// while (1) {
	// 	Monitor_Temperature();
	// 	Handle_Communication();
	// }
}
