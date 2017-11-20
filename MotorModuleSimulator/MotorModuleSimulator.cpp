#include "MotorModuleSimulator.h"

MotorModuleSimulator::MotorModuleSimulator(int id, int x, int y, int z) {
    this->id = id;
    this->length = 0;
    this->desiredLength = 0;
    this->position[0] = x;
    this->position[1] = y;
    this->position[2] = z;
}

void MotorModuleSimulator::runSim() {
    while (true) {


        if (length == desiredLength) {
            std::cout << "Motor " << getId() << ": done" << std::endl;
            break;
        }
        if (length > desiredLength) {
            setLength(length - 0.0001);
        } else if (length < desiredLength) {
            setLength(length + 0.0001);
        }

        std::this_thread::sleep_for(std::chrono::nanoseconds(1));
    }
}

// start of Arduino code
typedef enum {
    LISTENING,
    SETTING_LENGTH,
    MOVING,
    DONE
} StateType;

typedef struct {
    StateType State;

    void (*func)(void);
} StateMachineType;

StateMachineType StateMachine[] = {
        {LISTENING,      Sm_Listening},
        {DONE,           Sm_Done},
        {SETTING_LENGTH, Sm_SettingLength},
        {MOVING,         Sm_Moving}
};

StateType SmState = LISTENING;

std::string Command;

void loop() {
    if (SmState < 4) {
        (*StateMachine[SmState].func)();
    } else {
    }
}

void Sm_Listening(void) {
    // wait for commands
    // if command is received
    // Set command variable
    // Check if for correct module
    // execute
}

void Sm_SettingLength(void) {
    // Set correct length
}


void Sm_Moving(void) {
    // Move rope to desired length
}

void Sm_Done(void) {
    // transmit done and wait for received
}