#ifndef CONTROLS_H
#define CONTROLS_H

#include "stm32l4xx_hal.h"


typedef struct {
    float throttle_input; // -1 to 1
    float pitch_input; // -1 to 1
    float roll_input; // -1 to 1
    float yaw_input; // -1 to 1
} Control;

extern Control control;
extern UART_HandleTypeDef huart2; // Ensure UART2 is initialized in STM32CubeMX

char get_user_input();
void handle_controls(char input);

#endif