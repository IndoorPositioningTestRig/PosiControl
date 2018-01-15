#include <cstring>
#include <unistd.h>
#include "CommunicationHandler.h"

CommunicationHandler::CommunicationHandler(char *serialPort) {
    arduino = new SerialPort(serialPort);
    if (arduino->isConnected())
        cout << "Connection Established" << endl;
    else
        cout << "ERROR, check port name" << endl;
}

CommunicationHandler::~CommunicationHandler() {
    delete arduino;
}

void CommunicationHandler::setDesiredLength(int mid, int length, int speed) {
    if (arduino->isConnected())
        sendCommand(createCommand1(to_string(mid), to_string(length), to_string(speed)));
}

void CommunicationHandler::executeMove(vector<MotorModule *> motors) {
    if (arduino->isConnected()) {
        // create checklist
        for (auto &motor : motors) {
            motor->isMoving = true;
        }

        // Send command
        sendCommand(createCommand2("0"));

        // Sleep for 1 second
        usleep(1000000);

        // Check lengths of all modules
        for (auto &motor : motors) {
            motor->setLength(getLength(motor->getId()));
            motor->isMoving = false;
        }
    }
}

void CommunicationHandler::executeMove(vector<MotorModule *> motors, int mid) {
    if (arduino->isConnected()) {
        for (auto &motor : motors) {
            if (motor->getId() == mid)
                motor->isMoving = true;
        }

        // Send command
        sendCommand(createCommand2(to_string(mid)));

        // Sleep for 1 second
        usleep(1000000);

        // Check length of module
        for (auto &motor : motors) {
            if (motor->getId() == mid) {
                motor->setLength(getLength(motor->getId()));
                motor->isMoving = false;
            }
        }
    }
}

int CommunicationHandler::getLength(int mid) {
    if (arduino->isConnected()) {
        // send command
        sendCommand(createCommand6(to_string(mid)));
        usleep(100000);

        // wait for response
        string response = "";
        bool isWaiting = true;
        while (isWaiting) {
            auto *incomingData = new char[10];
            int read_result = arduino->readSerialPort(incomingData, MAX_DATA_LENGTH);
            if (read_result > 0) {
                response.append(incomingData);
                cout << "Received message: " << response << endl;
                if (response.find('#') != string::npos) {
                    isWaiting = false;
                }
            } else {
                sendCommand(createCommand6(to_string(mid)));
            }
        }
        string position = response.substr(response.find('|', 4) + 1, response.find('#'));
        response.clear();
        return stoi(position);
    }
}

void CommunicationHandler::setLength(int mid, int pos) {
    if (arduino->isConnected())
        sendCommand(createCommand7(to_string(mid), to_string(pos)));
}

void CommunicationHandler::sendCommand(std::string command) {
    auto *cCommand = new char[command.length() + 1];
    std::strcpy(cCommand, command.c_str());
    arduino->writeSerialPort(cCommand, static_cast<unsigned int>(strlen(cCommand)));
    delete[] cCommand;
}

string CommunicationHandler::createCommand1(const string &MID, const string &Length, const string &Speed) {
    string command;
    command.append("*1|");
    command.append(MID);
    command.append("|");
    command.append(Length);
    command.append("|");
    command.append(Speed);
    command.append("#");
    return command;
}

string CommunicationHandler::createCommand2(const string &MID) {
    string command;
    command.append("*2|");
    command.append(MID);
    command.append("#");
    return command;
}

string CommunicationHandler::createCommand6(const string &MID) {
    string command;
    command.append("*6|");
    command.append(MID);
    command.append("#");
    return command;
}

string CommunicationHandler::createCommand7(const string &mid, const string &pos) {
    string command;
    command.append("*7|");
    command.append(mid);
    command.append("|");
    command.append(pos);
    command.append("#");
    return command;
}

