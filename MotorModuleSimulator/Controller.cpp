#include "Controller.h"

Controller::Controller() {
    MotorModuleSimulator motorModuleSimulator1 = MotorModuleSimulator(1, 0, 0, 0);
    MotorModuleSimulator motorModuleSimulator2 = MotorModuleSimulator(2, 6, 0, 0);
    MotorModuleSimulator motorModuleSimulator3 = MotorModuleSimulator(3, 0, 8, 0);
    MotorModuleSimulator motorModuleSimulator4 = MotorModuleSimulator(4, 6, 8, 0);
    MotorModuleSimulator motorModuleSimulator5 = MotorModuleSimulator(5, 0, 0, 5);
    MotorModuleSimulator motorModuleSimulator6 = MotorModuleSimulator(6, 6, 0, 5);
    MotorModuleSimulator motorModuleSimulator7 = MotorModuleSimulator(7, 0, 8, 5);
    MotorModuleSimulator motorModuleSimulator8 = MotorModuleSimulator(8, 6, 8, 5);

    motors.push_back(&motorModuleSimulator1);
    motors.push_back(&motorModuleSimulator2);
    motors.push_back(&motorModuleSimulator3);
    motors.push_back(&motorModuleSimulator4);
    motors.push_back(&motorModuleSimulator5);
    motors.push_back(&motorModuleSimulator6);
    motors.push_back(&motorModuleSimulator7);
    motors.push_back(&motorModuleSimulator8);

    std::string x;
    std::cout << "X: ";
    getline(std::cin, x);

    std::string y;
    std::cout << "Y: ";
    getline(std::cin, y);

    std::string z;
    std::cout << "Z: ";
    getline(std::cin, z);


    setProbePosition(std::stod(x), std::stod(y), std::stod(z));

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

void Controller::setProbePosition(double x, double y, double z) {
    probePosition[0] = x;
    probePosition[1] = y;
    probePosition[2] = z;
    for (MotorModuleSimulator *motor: motors) {
        double length = sqrt(pow(motor->getX() - x, 2) + pow(motor->getY() - y, 2) + pow(motor->getZ() - z, 2));
        motor->setDesiredLength(length);
    }
}
