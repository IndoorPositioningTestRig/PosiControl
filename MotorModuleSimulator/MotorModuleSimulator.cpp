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
        if (desiredLength - 1 < length && length < desiredLength + 1) {
            std::cout << "Motor " << getId() << ": done" << std::endl;
            break;
        } else if (length > desiredLength + speed) {
            setLength(length - speed);
        } else if (length < desiredLength - speed) {
            setLength(length + speed);
        } else if (length > desiredLength) {
            setLength(length + (desiredLength - length));
        } else if (length < desiredLength) {
            setLength(length + (desiredLength - length));
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}