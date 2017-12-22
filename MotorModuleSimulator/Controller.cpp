#include "Controller.h"

using namespace std;


Controller::Controller(char *port_name) {

    rs485 = new CommunicationHandler(port_name);

    // Create motor modules
    addMotorModule(1, 0, 0, 0);
//    addMotorModule(2, 2000, 0, 0);
//    addMotorModule(3, 0, 2000, 0);
//    addMotorModule(4, 2000, 2000, 0);
//    addMotorModule(5, 0, 0, 2000);
//    addMotorModule(6, 2000, 0, 2000);
//    addMotorModule(7, 0, 2000, 2000);
//    addMotorModule(8, 2000, 2000, 2000);


    std::string command = "";
    std::string x;
    std::string y;
    std::string z;
    bool isRunning = true;
    while (isRunning) {
        cout << "Commands:" << endl;
        cout << "1: Set length" << endl;
        cout << "2: Go" << endl;
        cout << "3: Status" << endl;
        cout << "0: quit" << endl;
        getline(cin, command);
        switch (stoi(command)) {
            case 1:
                // request x, y, z coordinates
                std::cout << "X: ";
                getline(std::cin, x);

                std::cout << "Y: ";
                getline(std::cin, y);

                std::cout << "Z: ";
                getline(std::cin, z);

                setProbePosition(std::stod(x), std::stod(y), std::stod(z));
                for (MotorModule *motor: motors) {
                    rs485->setLength(motor->getId(), motor->getDesiredLength(), motor->getSpeed());
                }
                break;
            case 2:
                // send go
                rs485->executeMove(motors);
                break;
            case 3:
                cout << "----------Status---------" << endl;
                for (MotorModule *motor: motors) {
                    cout << "Motor module: " << motor->getId() << endl;
                    cout << "X: " << motor->getX() << " - Y: " << motor->getY() << " - Z: " << motor->getZ() << endl;
                    cout << "Desired length: " << motor->getDesiredLength() << " - Length: " << motor->getLength()
                         << endl;
                    cout << "Speed: " << motor->getSpeed() << endl;
                    cout << "-------------------------" << endl;
                }
                break;
            case 0:
                cout << "Bye" << endl;
                isRunning = false;
                break;
            default:
                cout << "unknown command" << endl;
                command = "";
                break;
        }
    }
    std::string a;
    getline(std::cin, a);
}

void Controller::setProbePosition(double x, double y, double z) {
    probePosition[0] = x;
    probePosition[1] = y;
    probePosition[2] = z;
    for (MotorModule *motor: motors) {
        double a = pow(motor->getX() - x, 2);
        double b = pow(motor->getY() - y, 2);
        double c = pow(motor->getZ() - z, 2);
        int length = int(sqrt(a + b + c));
        int time = 10; // 10 seconds to move to the position
        int speed = length / time;
        motor->commandSetLength(length, speed);
    }
}

void Controller::addMotorModule(int id, int x, int y, int z) {
    motors.push_back(new MotorModule(id, x, y, z));
}
