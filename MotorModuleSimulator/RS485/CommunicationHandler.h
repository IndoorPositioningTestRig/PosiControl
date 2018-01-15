#pragma once

#include <iostream>
#include <thread>
#include <vector>
#include "SerialPort.h"
#include "../MotorModule.h"

using namespace std;

class CommunicationHandler {
public:
    CommunicationHandler(char *serialPort);

    void setLength(int mid, int length, int speed);

    void executeMove( vector<MotorModule *> motors);
    int getEncoderPos(int mid);
    void setEncoderPos(int mid, int pos);
private:
    SerialPort *arduino;

    char *createCommand1(const string &mid, const string &length, const string &speed);

    char *createCommand3(const string &mid);


    std::string createCommand4(const string &mid);
    char * createCommand6(const string &mid);
    char * createCommand7(const string &mid, const string & pos);
};