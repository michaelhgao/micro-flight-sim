typedef struct {
    // aircraft state
    float x, y, z;
    float vx, vy, vz;
    float pitch, roll, yaw;
    float pitch_rate, roll_rate, yaw_rate;

} State;

typedef struct {
    float throttle_input; // -1 to 1
    float pitch_input; // -1 to 1
    float roll_input; // -1 to 1
    float yaw_input; // -1 to 1
} Control;

extern State state;
extern Control control;

void update_physics(float dt);
void handle_controls(char input);