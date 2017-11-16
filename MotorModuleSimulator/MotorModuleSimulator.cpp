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
