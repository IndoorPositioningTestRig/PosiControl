//
// Created by mauro on 15-12-2017.
//

#include "CommunicationHandler.h"

CommunicationHandler::CommunicationHandler(char *serialPort) {
    arduino = new SerialPort(serialPort);
    if (arduino->isConnected())
        cout << "Connection Established" << endl;
    else
        cout << "ERROR, check port name" << endl;
}

void CommunicationHandler::setLength(int mid, int length, int speed) {
    if (arduino->isConnected()) {
        // Create command
        char *cCommand = createCommand1(to_string(mid), to_string(length), to_string(speed));

        // Send command and delete the command
        arduino->writeSerialPort(cCommand, strlen(cCommand));
        delete[] cCommand;

        // Create expected response
        string response = createCommand4(to_string(mid));

        // Wait for response
        bool isWaiting = true;
        string message;
        while (isWaiting) {
            char *incomingData = new char[4];
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
        }
        char *cCommand3 = createCommand3(to_string(mid));
        arduino->writeSerialPort(cCommand3, strlen(cCommand3));
    }
}

void CommunicationHandler::executeMove() {
    if (arduino->isConnected()) {
        // Create command
        char *cCommand = "2|0#";

        // Send command
        arduino->writeSerialPort(cCommand, strlen(cCommand));

        // Wait for responses from all modules

        // Send acknowledge

    }
}

char *CommunicationHandler::createCommand1(const string &MID, const string &Length, const string &Speed) {
    string command;
    command.append("1|");
    command.append(MID);
    command.append("|");
    command.append(Length);
    command.append("|");
    command.append(Speed);
    command.append("#");
    char *cCommand = new char[command.length() + 1];
    strcpy(cCommand, command.c_str());
    return cCommand;
}

char *CommunicationHandler::createCommand3(const string &MID) {
    string command;
    command.append("3|");
    command.append(MID);
    command.append("#");
    char *cCommand = new char[command.length() + 1];
    strcpy(cCommand, command.c_str());
    return cCommand;
}

string CommunicationHandler::createCommand4(const string &MID) {
    string response;
    response.append("4|");
    response.append(MID);
    response.append("#");
    return response;
}
