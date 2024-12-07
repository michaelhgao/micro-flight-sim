#include "physics.h"
#include "controls.h"
#include "constants.h"


char get_user_input() {
    char input;
    HAL_UART_Receive(&huart2, (uint8_t *)&input, 1, HAL_MAX_DELAY);
    return input;

}

void handle_controls(char input) {
    switch (input) {
        case 'w':
            control.throttle_input += 0.1;
            break;
        case 's':
            control.throttle_input -= 0.1;
            break;
        case 'a':
            control.roll_input = -1;
            break;
        case 'd':
            control.roll_input = 1;
            break;
        case 'i':
            control.pitch_input = 1;
            break;
        case 'k':
            control.pitch_input = -1;
            break;
    }

}