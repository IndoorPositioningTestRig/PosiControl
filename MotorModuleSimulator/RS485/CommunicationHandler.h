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

    int getEncoderPos(int mid);
    void setEncoderPos(int mid, int position);

private:
    SerialPort *arduino;

    void sendCommand(std::string command);

    string createCommand1(const string &mid, const string &length, const string &speed);

    string createCommand2();

    string createCommand3(const string &mid);

    string createCommand4(const string &mid);

    string createCommand6(const string &mid);

    string createCommand7(const string &mid, const string &pos);
};