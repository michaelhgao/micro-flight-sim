#include "physics.h"
#include "controls.h"
#include "constants.h"
#include <stdio.h>


// Define shared variables
State state = {0};
Control control = {0};


void display_state() {
    char buffer[100];

    snprintf(buffer, sizeof(buffer), 
             "Pos: x=%.2f, y=%.2f, z=%.2f\nVel: vx=%.2f, vy=%.2f, vz=%.2f\n",
             state.x, state.y, state.z, state.vx, state.vy, state.vz);

    HAL_UART_Transmit(&huart2, (uint8_t *)buffer, strlen(buffer), HAL_MAX_DELAY);

}

int main() {
    float dt = 0.01;

    while (1) {
        // Call control logic
        handle_controls(get_user_input());

        // Update physics
        update_physics(dt);

        // Output state
        display_state();

        HAL_Delay((int)(dt * 1000));
        
    }

    return 0;

}
