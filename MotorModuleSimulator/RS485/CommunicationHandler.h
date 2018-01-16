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

    void setDesiredLength(int mid, int length, int speed);

    void executeMove(vector<MotorModule *> motors);

    void executeMove(vector<MotorModule *> motors, int mid);

    int getLength(int mid);

    int getDesiredLengthAndSpeed(int mid);

    void setLength(int mid, int position);

private:
    SerialPort *arduino;

    char incomingData[20];

    void sendCommand(std::string command);

    string createCommand1(const string &mid, const string &length, const string &speed);

    string createCommand2(const string &mid);

    string createCommand3(const string &mid);

    string createCommand4(const string &mid);

    string createCommand5(const string &mid, const string &pos);


};