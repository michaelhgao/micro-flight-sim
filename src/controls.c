#include "state.h"
#include "constants.h"


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