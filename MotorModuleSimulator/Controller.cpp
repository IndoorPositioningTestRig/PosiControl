#include "Controller.h"


Controller::Controller() {
    // request x, y, z coordinates
    std::string x;
    std::cout << "X: ";
    getline(std::cin, x);

    std::string y;
    std::cout << "Y: ";
    getline(std::cin, y);

    std::string z;
    std::cout << "Z: ";
    getline(std::cin, z);

    // Create motor modules
    addMotorModule(1, 0, 0, 0);
    addMotorModule(2, 6, 0, 0);
    addMotorModule(3, 0, 8, 0);
    addMotorModule(4, 6, 8, 0);
    addMotorModule(5, 0, 0, 5);
    addMotorModule(6, 6, 0, 5);
    addMotorModule(7, 0, 8, 5);
    addMotorModule(8, 6, 8, 5);

    // Move the probe
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
            if (motor->getDesiredLength() - 0.01 < motor->getLength() && motor->getLength() < motor->getDesiredLength() + 0.01) {
                if (motor->simulator->joinable()) {
                    motor->simulator->join();
                }
            }
        }
        std::cout << std::endl;

        // Check if finished
        bool done = true;
        for (MotorModuleSimulator *motor: motors) {
            if (motor->getDesiredLength() - 0.01 > motor->getLength() || motor->getLength() > motor->getDesiredLength() + 0.01)
                done = false;
        }
        if (done)break;
    }
    std::string a;
    getline(std::cin, a);
}

void Controller::setProbePosition(double x, double y, double z) {
    probePosition[0] = x;
    probePosition[1] = y;
    probePosition[2] = z;
    for (MotorModuleSimulator *motor: motors) {
        double a = pow(motor->getX() - x, 2);
        double b = pow(motor->getY() - y, 2);
        double c = pow(motor->getZ() - z, 2);

        double length = sqrt(a + b + c);
        motor->setDesiredLength(length);
    }
}

void Controller::addMotorModule(int id, int x, int y, int z) {
    motors.push_back(new MotorModuleSimulator(id, x, y, z));
}
