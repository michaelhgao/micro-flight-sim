#include "physics.h"
#include "controls.h"
#include "constants.h"
#include <math.h>

Control control;

void controls_init() {
	control.throttle_input = 0;
	control.pitch_input = 0;
	control.roll_input = 0;
	control.yaw_input = 0;
}

char get_user_input() {
	char input;
	if (HAL_UART_Receive(&huart2, (uint8_t*) &input, sizeof(input),
			HAL_MAX_DELAY) == HAL_OK) {
		return input;
	}
	return '\0';

}

void handle_controls(const char input) {
	switch (input) {
	case 'w':
		control.throttle_input = fmin(control.throttle_input + 0.1f, 1.0f);
		break;
	case 's':
		control.throttle_input = fmax(control.throttle_input - 0.1f, -1.0f);
		break;
	case 'a':
		control.roll_input = -1.0f;
		break;
	case 'd':
		control.roll_input = 1.0f;
		break;
	case 'i':
		control.pitch_input = 1.0f;
		break;
	case 'k':
		control.pitch_input = -1.0f;
		break;
	default:
		control.roll_input = 0.0f;
		control.pitch_input = 0.0f;
		break;
	}

}
