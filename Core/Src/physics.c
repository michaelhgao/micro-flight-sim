#include "physics.h"
#include "controls.h"
#include "constants.h"


void update_physics(float dt) {
    // speed
    float speed = sqrt(state.vx * state.vx + state.vy * state.vy + state.vz * state.vz);

    // forces
    float thrust = control.throttle_input * MAX_THRUST;
    float drag = DRAG_COEFF * AIR_DENSITY * speed * speed * 0.5 * WING_AREA;
    float lift = LIFT_COEFF * AIR_DENSITY * speed * speed * 0.5 * WING_AREA;

    // vel update
    state.vx += (thrust - drag) / MASS * dt;
    state.vy += (0) / MASS * dt; // 0 for now
    state.vz += (lift - GRAVITY * MASS) / MASS * dt;

    // pos update
    state.x += state.vx * dt;
    state.y += state.vy * dt;
    state.z += state.vz * dt;

    // orientation update
    state.pitch += control.pitch_input * dt;
    state.roll += control.roll_input * dt;
    state.yaw += control.yaw_input * dt;

}