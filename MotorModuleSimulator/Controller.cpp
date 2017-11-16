#include "Controller.h"

Controller::Controller() {
    MotorModuleSimulator motorModuleSimulator = MotorModuleSimulator(1, 0, 0);
    motors.push_back(&motorModuleSimulator);

    setProbePosition(30, 40);

    std::cout << "Length: " << motorModuleSimulator.getLength() << std::endl;

    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << motorModuleSimulator.getLength() << " - " << motorModuleSimulator.getDesiredLength() << std::endl;
        if (motorModuleSimulator.getLength() == motorModuleSimulator.getDesiredLength())
            break;
    }

}

void Controller::setProbePosition(double x, double y) {
    probePosition[0] = x;
    probePosition[1] = y;
    for (MotorModuleSimulator *motor: motors) {
        motor->setDesiredLength(sqrt(pow(motor->getX() - x, 2) + pow(motor->getY() - y, 2)));
    }
}
