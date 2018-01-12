#include "Controller.h"

using namespace std;


Controller::Controller(char *port_name) {

    rs485 = new CommunicationHandler(port_name);

    // Create motor modules
    addMotorModule(1, 0, 0, 1840);
    addMotorModule(2, 1840, 0, 1840);
    addMotorModule(3, 1840, 1840, 1840);
    addMotorModule(4, 0, 1840, 1840);
//    addMotorModule(5, 0, 0, 2000);
//    addMotorModule(6, 2000, 0, 2000);
//    addMotorModule(7, 0, 2000, 2000);
//    addMotorModule(8, 2000, 2000, 2000);

    for (auto &motor : motors) {
        motor->setLength(1593);
    }

    std::string command;
    std::string x;
    std::string y;
    std::string z;
    bool isRunning = true;
    while (isRunning) {
        cout << "Commands:" << endl;
        cout << "1: Set length" << endl;
        cout << "2: Go" << endl;
        cout << "3: Status" << endl;
        cout << "4: Set motor length" << endl;
        cout << "0: quit" << endl;
        getline(cin, command);
        if (!command.empty()) {
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
                    cout << "Length set" << endl;
                    break;
                case 2:
                    // send go
                    rs485->executeMove(motors);
                    cout << "executing move" << endl;
                    break;
                case 3:
                    cout << "----------Status---------" << endl;
                    for (MotorModule *motor: motors) {
                        cout << "Motor module: " << motor->getId() << endl;
                        cout << "X: " << motor->getX() << " - Y: " << motor->getY() << " - Z: " << motor->getZ()
                             << endl;
                        cout << "Desired length: " << motor->getDesiredLength() << " - Length: " << motor->getLength()
                             << endl;
                        cout << "Speed: " << motor->getSpeed() << endl;
                        cout << "-------------------------" << endl;
                    }
                    break;
                case 4:
                    cout << "----------Custom Motor Length---------" << endl;
                    setCustomMotorLength();
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
            command = "";
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
        auto desiredLength = int(sqrt(a + b + c));
        int time = 3; // 10 seconds to move to the position
        int speed = abs((motor->getLength() - desiredLength) / time);
        motor->commandSetLength(desiredLength, speed);
    }
}

void Controller::addMotorModule(int id, int x, int y, int z) {
    motors.push_back(new MotorModule(id, x, y, z));
}

void Controller::setCustomMotorLength(){
    cout << "Select motor(s) finish with 0" << endl;
    for(int i = 0; i < motors.size(); i++){
        cout << "motor: " << motors[i]->getId() << endl;
    }
    bool done = false;
    vector<int> motorIds;
    while(!done){
        string s;
        getline(cin, s);
        int mId = stoi(s);
        if(mId != 0){
            motorIds.push_back(mId);
        }else{
            done = true;
        }
    }

    int length = rs485->getEncoderPos(1);


}
