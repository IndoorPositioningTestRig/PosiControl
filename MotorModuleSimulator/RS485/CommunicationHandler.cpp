#include <cstring>
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

void CommunicationHandler::setLength(int mid, int length, int speed) {
    if (arduino->isConnected()) {

        // Create set length command and publish it on the bus
        sendCommand(createCommand1(to_string(mid), to_string(length), to_string(speed)));

        // Wait for Done
        string response = createCommand4(to_string(mid));
        bool isWaiting = true;
        string message;
        while (isWaiting) {
            auto *incomingData = new char[4];
            int read_result = arduino->readSerialPort(incomingData, MAX_DATA_LENGTH);
            if (read_result > 0) {
                message.append(incomingData);
                cout << "Received message: " << message << endl;
                if (message.find('#') != string::npos) {
                    string msg = message.substr(0, message.find('#') + 1);
                    int compare = msg.compare(response);
                    if (compare == 0)
                        isWaiting = false;
                    message.clear();
                }
            }
            delete[] incomingData;
        }

        // Send Acknowledge to the correct module
        sendCommand(createCommand3(to_string(mid)));
    }
}

void CommunicationHandler::executeMove(vector<MotorModule *> motors) {

    // create checklist
    bool list[motors.size()];
    for (int i = 0; i < motors.size(); ++i) {
        list[i] = false;
    }

    if (arduino->isConnected()) {
        // Send command
        sendCommand(createCommand2());

        // Wait for responses from all modules
        bool isWaiting = true;
        string message;
        while (isWaiting) {
            auto *incomingData = new char[4];
            int read_result = arduino->readSerialPort(incomingData, MAX_DATA_LENGTH);
            if (read_result > 0) {
                message.append(incomingData);
                cout << "Received message: " << message << endl;
                if (message.find('#') != string::npos) {
                    unsigned long position = message.find('|');
                    string mid = message.substr(position + 1, position + 2);
                    list[stoi(mid) - 1] = true;

                    // Send Acknowledge to the correct module
                    sendCommand(createCommand3(mid));

                    message.clear();
                    bool hasFalse = true;
                    for (int i = 0; i < motors.size(); ++i) {
                        if (!list[i])
                            hasFalse = false;
                    }
                    if (hasFalse)
                        isWaiting = false;
                }
            }
            delete[] incomingData;
        }
        for (auto &motor : motors) {
            motor->setLength(motor->getDesiredLength());
        }
    }
}

int CommunicationHandler::getEncoderPos(int mid) {

    // send command
    sendCommand(createCommand6(to_string(mid)));

    // wait for response
    string response;
    bool isWaiting = true;
    while (isWaiting) {
        auto *incomingData = new char[50];
        int read_result = arduino->readSerialPort(incomingData, MAX_DATA_LENGTH);
        if (read_result > 0) {
            response.append(incomingData);
            cout << "Received message: " << response << endl;
            if (response.find('#') != string::npos) {
                string msg = response.substr(0, response.find('#') + 1);
                isWaiting = false;
            }
        }
        delete[] incomingData;
    }

    int first = response.find('|', 4) + 1;
    int last = response.find('#');
    string position = response.substr(first, last - first);
    int length = stoi(position);
    return length;
}

void CommunicationHandler::setEncoderPos(int mid, int pos){
    sendCommand(createCommand6(to_string(mid)));
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

string CommunicationHandler::createCommand2() {
    return "*2|0#";
}

string CommunicationHandler::createCommand3(const string &MID) {
    string command;
    command.append("*3|");
    command.append(MID);
    command.append("#");
    return command;
}

string CommunicationHandler::createCommand4(const string &MID) {
    string command;
    command.append("*4|");
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
