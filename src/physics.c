#include "state.h"
#include "constants.h"


void update_physics(float dt) {

    // forces
    float thrust = control.throttle_input * MAX_THRUST;
    float lift = LIFT_COEFF * control.pitch_input * state.vx;
    float drag = DRAG_COEFF * (state.vx * state.vx);

    // vel update
    state.vx += (thrust - drag) / MASS * dt;
    state.vz += (lift - GRAVITY * MASS) / MASS * dt;

    // pos update
    state.x += state.vx * dt;
    state.z += state.vz * dt;

    // orientation update
    state.pitch += control.pitch_input * dt;
    state.roll += control.roll_input * dt;
    state.yaw += control.yaw_input * dt;

}