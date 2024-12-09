#include "physics.h"
#include "controls.h"
#include "constants.h"
#include <math.h>

State state;

void physics_init() {
	state.x = 0;
	state.y = 0;
	state.z = 0;
	state.vx = 0;
	state.vy = 0;
	state.vz = 0;
	state.pitch = 0;
	state.roll = 0;
	state.yaw = 0;
	state.pitch_rate = 0;
	state.roll_rate = 0;
	state.yaw_rate = 0;
}

void update_physics(float dt) {
	// speed
	float speed = sqrt(
			state.vx * state.vx + state.vy * state.vy + state.vz * state.vz);

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
