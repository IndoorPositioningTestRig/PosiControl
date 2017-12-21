#include "MotorModuleSimulator.h"

void MotorModuleSimulator::runSim() {
    while (true) {
        if (getDesiredLength() - 1 < getLength() && getLength() < getDesiredLength() + 1) {
            std::cout << "Motor " << getId() << ": done" << std::endl;
            break;
        } else if (getLength() > getDesiredLength() + getSpeed()) {
            setLength(getLength() - getSpeed());
        } else if (getLength() < getDesiredLength() - getSpeed()) {
            setLength(getLength() + getSpeed());
        } else if (getLength() > getDesiredLength()) {
            setLength(getLength() + (getDesiredLength() - getLength()));
        } else if (getLength() < getDesiredLength())
            setLength(getLength() + (getDesiredLength() - getLength()));
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}