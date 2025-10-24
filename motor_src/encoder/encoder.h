#ifndef __ENCODER_H
#define __ENCODER_H

#include <stdlib.h>

typedef struct {
	uint32_t input;
} UART_Info;

void Encoder_Init(uint8_t steps, uint8_t time); // init how fast motor should respond
float Encoder_getAngle(void); // returns the current angle in "xxx.xx" format
void Encoder_setAngle(float new_angle); // set new angle with "xxx.xx" format


#endif
