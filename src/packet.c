#include "tusb.h"

void serializeData(char* write_buffer, uint32_t buffer_length) {
	while (!tud_cdc_available()) {}

	tud_cdc_write(write_buffer, buffer_length);
	tud_cdc_write_flush();
}
