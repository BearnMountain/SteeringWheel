#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/gpio.h"
#include "tusb.h"

// Pin Defs
#define STEERING_ADC	26
#define THROTTLE_ADC	27
#define BRAKE_ADC   	28
#define BUTTON_ADC  	29
#define PEDAL_LEFT  	0
#define PEDAL_RIGHT 	1

// HID Report 
typedef struct {
	uint8_t  report_id;
	uint16_t steering;
	uint16_t throttle;
	uint16_t brake;
	uint16_t buttons; // bit field for 10 buttons
} __attribute__((packed)) wheel_report;

// Init Hardware
void setupHardware(void) {
	stdio_init_all();

	// Initialize ADC
	adc_init();
	adc_gpio_init(STEERING_ADC);
	adc_gpio_init(THROTTLE_ADC);
	adc_gpio_init(BRAKE_ADC);
	adc_gpio_init(BUTTON_ADC);

	// Initialize GPIO
	gpio_init(PEDAL_LEFT);
	gpio_set_dir(PEDAL_LEFT, GPIO_IN);
	gpio_pull_up(PEDAL_LEFT);

	gpio_init(PEDAL_RIGHT);
	gpio_set_dir(PEDAL_RIGHT, GPIO_IN);
	gpio_pull_up(PEDAL_RIGHT);
}

uint16_t readSteering(void) {}
uint16_t readThrottle(void) {}
uint16_t readBrake(void) {}
uint16_t readButtons(void) {}

void shipWheelReport(void){}

void main(void) {
	// init hardware
	setupHardware();
	tusb_init();

	while (1) {
		tud_task(); // process usb tasks
		shipWheelReport();
		sleep_ms(1); // 1000 data requests a second
	}
}
