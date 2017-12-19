#pragma once

#include <iostream>
#include <thread>
#include "SerialPort.h"

class CommunicationHandler {
public:
    CommunicationHandler() {
        arduino = new SerialPort("\\\\.\\COM15");
        if (arduino->isConnected())
            std::cout << "Connection Established" << std::endl;
        else
            std::cout << "ERROR, check port name" << std::endl;
    };

    void setLength(int mid, int length, int speed) {
        if (arduino->isConnected()) {
            std::string command = "";
            command.append("1|");
            command.append(std::to_string(mid));
            command.append("|");
            command.append(std::to_string(length));
            command.append("|");
            command.append(std::to_string(speed));
            command.append("#");
            char *cstr = new char[command.length() + 1];
            strcpy(cstr, command.c_str());
            arduino->writeSerialPort(cstr, strlen(cstr));
            delete[] cstr;
            std::string response = "";
            response.append("4|");
            response.append(std::to_string(mid));
            response.append("#");
            bool isWaiting = true;
            std::string message;
            while (isWaiting) {
                char *incomingData = new char[4];
                int read_result = arduino->readSerialPort(incomingData, MAX_DATA_LENGTH);
                if (read_result > 0) {
                    message.append(incomingData);
                    std::cout << message << std::endl;
                    if (message.find('#') != std::string::npos) {
                        std::string msg = message.substr(0, message.find('#') + 1);
                        int compare = msg.compare(response);
                        if (compare == 0)
                            isWaiting = false;
                        message.clear();
                    }
                }
            }
        }
    };

    void executeMove() {
        if (arduino->isConnected()) {
            std::string command = "2|0#";
            char *cstr = new char[command.length() + 1];
            strcpy(cstr, command.c_str());
            arduino->writeSerialPort(cstr, strlen(cstr));
            delete[] cstr;
        }
    };

private:
    SerialPort *arduino;
};