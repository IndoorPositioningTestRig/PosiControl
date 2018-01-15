#pragma once

#include <iostream>
#include <thread>
#include <vector>
#include "SerialPort.h"
#include "../MotorModule.h"

using namespace std;

class CommunicationHandler {
public:
    explicit CommunicationHandler(char *serialPort);

    ~CommunicationHandler();

    void setLength(int mid, int length, int speed);

    void executeMove(vector<MotorModule *> motors);

private:
    SerialPort *arduino;

    string createCommand1(const string &mid, const string &length, const string &speed);

    string createCommand2();

    string createCommand3(const string &mid);

    string createCommand4(const string &mid);

    void sendCommand(std::string command);
};