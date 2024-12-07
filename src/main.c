#include "state.h"

#include "controls.c"
#include "physics.c"

// Define shared variables
State state = {0};
float throttle_input = 0.0;
float pitch_input = 0.0;
float roll_input = 0.0;
float yaw_input = 0.0;


int main(void) {
    // Initialization code here...

    while (1) {
        // Call control logic
        handle_controls(get_user_input());

        // Update physics
        update_physics(0.05);

        // Output state
        transmit_flight_data();
    }
}
