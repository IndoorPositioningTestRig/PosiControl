#include "Controller.h"

using namespace std;


Controller::Controller(char *port_name) {

    rs485 = new CommunicationHandler(port_name);

    // Create motor modules
    addMotorModule(1, 0, 0, 1840);
    addMotorModule(2, 1840, 0, 1840);
    addMotorModule(3, 1840, 1840, 1840);
    addMotorModule(4, 0, 1840, 1840);

    for (auto &motor : motors) {
        motor->setLength(1683);
    }
    int figure[4][3] = {
            {920, 920,  1150},
            {920, 1150, 1150},
            {920, 1150, 920},
            {920, 920,  920}
    };;
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
        cout << "5: execute square" << endl;
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
                case 5:
                    // execute square
                    cout << "Enter loop" << endl;
                    for (auto &i : figure) {
                        cout << "setting probe position" << endl;
                        setProbePosition(i[0], i[1], i[2]);
                        for (MotorModule *motor: motors) {
                            rs485->setLength(motor->getId(), motor->getDesiredLength(), motor->getSpeed());
                        }
                        cout << "executing move" << endl;
                        rs485->executeMove(motors);
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
            command = "";
        }
    }
    std::string a;
    getline(std::cin, a);
}

Controller::~Controller() {
    for (auto &motor : motors) {
        delete motor;
    }
    delete rs485;
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
        int time = 3; // 3 seconds to move to the position
        int speed = abs((motor->getLength() - desiredLength) / time);
        motor->setSpeed(speed);
        motor->setDesiredLength(desiredLength);
    }
}

void Controller::addMotorModule(int id, int x, int y, int z) {
    motors.push_back(new MotorModule(id, x, y, z));
}

void Controller::setCustomMotorLength(){
    cout << "Select motor(s) finish with enter or 0" << endl;
    for(int i = 0; i < motors.size(); i++){
        cout << "motor: " << motors[i]->getId() << endl;
    }
    bool done = false;
    vector<int> motorIds;
    while(!done){
        string s;
        getline(cin, s);
        if(s.length() < 1){
            done = true;
            break;
        }
        int mId = stoi(s);
        if(mId != 0){
            motorIds.push_back(mId);
        }else{
            done = true;
        }
    }

    vector<int> encoderPositions;
    for(int mId : motorIds){
        int length = rs485->getEncoderPos(mId);
        encoderPositions.push_back(length);
    }

    cout << "selected motors:" << endl;
    for(int i = 0; i < motorIds.size(); i++){
        cout << "motor: " << motorIds[i] << " motorLength: " << encoderPositions[i]<< endl;
    }
    vector<int> newPositions;
    cout << "set desired position"<< endl;
    for(int i = 0; i < motorIds.size(); i++){
        cout << "motor: " << motorIds[i];
        string newPosString;
        getline(cin, newPosString);
        newPositions.push_back(stoi(newPosString));
    }
    cout << "done" <<  "sending data to modules.." << endl;
    for(int i = 0; i < motorIds.size(); i ++){
        rs485->setLength(motorIds[i],newPositions[i], 30);
    }
    cout << "done, press enter to move" << endl;
    cout << "moving motors.." << endl;
    rs485->executeMove(motors);
    cout << "done" << endl;
}
