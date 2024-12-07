#ifndef PHYSICS_H
#define PHYSICS_H

typedef struct {
    // aircraft state
    float x, y, z;
    float vx, vy, vz;
    float pitch, roll, yaw;
    float pitch_rate, roll_rate, yaw_rate;

} State;

extern State state;

void update_physics(float dt);

#endif