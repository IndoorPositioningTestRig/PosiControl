#include "Controller.h"

Controller::Controller() {
    MotorModuleSimulator motorModuleSimulator1 = MotorModuleSimulator(1, 0, 0);
    MotorModuleSimulator motorModuleSimulator2 = MotorModuleSimulator(2, 5, 0);
    MotorModuleSimulator motorModuleSimulator3 = MotorModuleSimulator(3, 0, 5);
    MotorModuleSimulator motorModuleSimulator4 = MotorModuleSimulator(4, 5, 5);

    motors.push_back(&motorModuleSimulator1);
    motors.push_back(&motorModuleSimulator2);
    motors.push_back(&motorModuleSimulator3);
    motors.push_back(&motorModuleSimulator4);

    setProbePosition(3, 4);

    while (true) {
        // Wait 100 milliseconds
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        // Print status
        for (MotorModuleSimulator *motor: motors) {
            std::cout <<
                      " ID: " << motor->getId() <<
                      " - Length: " << motor->getLength() <<
                      " - Desired: " << motor->getDesiredLength()
                      << std::endl;
        }
        std::cout << std::endl;

        // Check if finished
        bool done = true;
        for (MotorModuleSimulator *motor: motors) {
            if (motor->getLength() != motor->getDesiredLength())
                done = false;
        }
        if (done)break;
    }
}

void Controller::setProbePosition(double x, double y) {
    probePosition[0] = x;
    probePosition[1] = y;
    for (MotorModuleSimulator *motor: motors) {
        motor->setDesiredLength(sqrt(pow(motor->getX() - x, 2) + pow(motor->getY() - y, 2)));
    }
}
