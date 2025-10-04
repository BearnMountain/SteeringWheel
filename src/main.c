#include "pico/stdlib.h"

#include "packet.c"

#define MICRO_SHIFTER_LEFT  1
#define MICRO_SHIFTER_RIGHT 2
#define MOTOR_STEERING      3
#define BUTTON_ADC          4
#define LOAD_THROTTLE       5 
#define LOAD_BREAK          6

void initMicrocontroller();
void initPeripherals();

int main(void) {
	// Initialize the LED pin
	initMicrocontroller();

	uint8_t led = 0;
    bool last_state = 1; // button released (with pull-up, 1 = released)

    while (true) {
        bool current_state = gpio_get(13);

        // Detect transition from released (1) → pressed (0)
        if (last_state == 1 && current_state == 0) {
            led ^= 1;
            gpio_put(25, led);
        }

        last_state = current_state;
        sleep_ms(20); // debounce delay
    }

	return 0;
}

void initMicrocontroller() {
	stdio_init_all();
	//tusb_init();
	//adc_init();
	
	// test
	gpio_init(25);
	gpio_set_dir(25, GPIO_OUT);
	gpio_init(13);
	gpio_set_dir(13, GPIO_IN);
	gpio_pull_up(13);
}

void initPeripherals() {
	// micro shifters
	gpio_init(MICRO_SHIFTER_LEFT);
	gpio_set_dir(MICRO_SHIFTER_LEFT, GPIO_IN);
	gpio_init(MICRO_SHIFTER_RIGHT);
	gpio_set_dir(MICRO_SHIFTER_RIGHT, GPIO_IN);

	// motor controller
	gpio_init(MOTOR_STEERING);
	gpio_set_dir(MOTOR_STEERING, GPIO_IN);

	// button controls
	gpio_init(BUTTON_ADC);
	gpio_set_dir(BUTTON_ADC, GPIO_IN);

	// load cell movement
	gpio_init(LOAD_THROTTLE);
	gpio_set_dir(LOAD_THROTTLE, GPIO_IN);
	gpio_init(LOAD_BREAK);
	gpio_set_dir(LOAD_BREAK, GPIO_IN);
}
