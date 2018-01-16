#include "Controller.h"

using namespace std;

Controller::Controller(char *port_name) {

    // Initialise RS485 communication through arduino
    rs485 = new CommunicationHandler(port_name);

    // Create motor modules
    addMotorModule(1, 0, 0, 1840);
//    addMotorModule(2, 1840, 0, 1840);
//    addMotorModule(3, 1840, 1840, 1840);
//    addMotorModule(4, 0, 1840, 1840);

    // set hardcoded motor length
    for (auto &motor : motors) {
        motor->setLength(1683);
    }

    menu();
}

void Controller::addMotorModule(int id, int x, int y, int z) {
    motors.push_back(new MotorModule(id, x, y, z));
}

Controller::~Controller() {
    for (auto &motor : motors) {
        delete motor;
    }
    delete rs485;
}

void Controller::menu() {
    std::string command;
    bool isRunning = true;
    while (isRunning) {
        cout << "Commands:" << endl;
        cout << "1: Set probe position" << endl;
        cout << "2: Execute move" << endl;
        cout << "3: Status" << endl;
        cout << "4: Set motor length" << endl;
        cout << "5: Execute pattern" << endl;
        cout << "6: Calibrate modules" << endl;
        cout << "0: Exit" << endl;
        getline(cin, command);
        if (!command.empty()) {
            switch (stoi(command)) {
                case 1: // Setting length
                    setLength();
                    break;
                case 2: // Executing move
                    executeMove();
                    break;
                case 3: // Status
                    status();
                    break;
                case 4: // Set length for single motor
                    setCustomMotorLength();
                    break;
                case 5: // Execute defined pattern
                    executePattern();
                    break;
                case 6: // Setup probe
                    calibrateProbe();
                    break;
                case 0: // Exit
                    cout << "Bye" << endl;
                    isRunning = false;
                    break;
                default: // if the number is not known
                    cout << "unknown command" << endl;
                    break;
            }
            command = "";
        }
    }
    std::string a;
    getline(std::cin, a);
}

void Controller::setLength() {

    // request x, y, z coordinates
    string x, y, z;

    cout << "Please enter your Coordinates." << endl;
    cout << "X: ";
    getline(cin, x);

    cout << "Y: ";
    getline(cin, y);

    cout << "Z: ";
    getline(cin, z);

    cout << "Calculating length." << endl;
    setProbePosition(stod(x), stod(y), stod(z));

    cout << "Sending length to modules." << endl;
    for (MotorModule *motor: motors) {
        rs485->setDesiredLength(motor->getId(), motor->getDesiredLength(), motor->getSpeed());
    }
    cout << "All modules have the correct length" << endl;
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

void Controller::executeMove() {
    cout << "Executing move." << endl;
    rs485->executeMove(motors);
}

void Controller::status() {
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
}

void Controller::setCustomMotorLength() {
    cout << "----------Custom Motor Length---------" << endl;
    cout << "Select motor(s) finish with enter or 0" << endl;
    for (auto &motor : motors) {
        cout << "motor: " << motor->getId() << endl;
    }

    bool done = false;
    vector<int> motorIds;
    while (!done) {
        string s;
        getline(cin, s);
        if (s.length() < 1) {
            done = true;
            break;
        }
        int mId = stoi(s);
        if (mId != 0) {
            motorIds.push_back(mId);
        } else {
            done = true;
        }
    }

    vector<int> encoderPositions;
    for (int mId : motorIds) {
        int length = rs485->getLength(mId);
        encoderPositions.push_back(length);
    }

    cout << "selected motors:" << endl;
    for (int i = 0; i < motorIds.size(); i++) {
        cout << "motor: " << motorIds[i] << " motorLength: " << encoderPositions[i] << endl;
    }

    vector<int> newPositions;
    cout << "set desired position: " << endl;
    for (int motorId : motorIds) {
        cout << "motor " << motorId << " : ";
        string newPosString;
        getline(cin, newPosString);
        newPositions.push_back(stoi(newPosString));
    }
    cout << "Done setting positions." << endl;
    cout << "sending data to modules.." << endl;
    for (int i = 0; i < motorIds.size(); i++) {
        rs485->setDesiredLength(motorIds[i], newPositions[i], 30);
    }

    cout << "moving motors.." << endl;
    for (int i = 0; i < motorIds.size(); i++) {
        rs485->executeMove(motors, motorIds[i]);
    }
    cout << "done" << endl;
}

void Controller::executePattern() {
    int figure[4][3] = {
            {920, 920,  1150},
            {920, 1150, 1150},
            {920, 1150, 920},
            {920, 920,  920}
    };;
    cout << "Enter loop" << endl;
    for (auto &i : figure) {
        cout << "setting probe position" << endl;
        setProbePosition(i[0], i[1], i[2]);
        for (MotorModule *motor: motors) {
            rs485->setDesiredLength(motor->getId(), motor->getDesiredLength(), motor->getSpeed());
        }
        cout << "executing move" << endl;
        rs485->executeMove(motors);
    }
}

void Controller::calibrateProbe() {
    cout << "Probe setup." << endl;
    cout << "place the probe on a known position, press enter to continue" << endl;
    string input;
    getline(cin, input);
    for (auto &m : motors) {
        int length = rs485->getLength(m->getId());
        m->setEncoderPos(length);
    }
    cout << "current motor lengths" << endl;
    for (auto &m: motors) {
        cout << "motor " << m->getId() << " length: " << m->getEncoderPos() << endl;
    }
    cout << "set new motor lengths: " << endl;
    for (auto &m: motors) {
        cout << "motor " << m->getId() << endl;
        string lengthString;
        getline(cin, lengthString);
        int encoderLength = stoi(lengthString);
        m->setEncoderPos(encoderLength);
    }
    cout << "program setting correct motor length.. " << endl;
    for (auto &m : motors) {
        rs485->setLength(m->getId(), m->getEncoderPos());
    }
    cout << "done" << endl;
}





