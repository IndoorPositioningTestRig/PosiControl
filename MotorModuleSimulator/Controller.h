#pragma once

#include <vector>
#include <iostream>
#include <chrono>
#include <thread>
#include <cmath>
#include "RS485/CommunicationHandler.h"

class Controller {
public:
    explicit Controller(char *port_name);

    ~Controller();

private:
    double probePosition[3];
    std::vector<MotorModule *> motors;
    CommunicationHandler *rs485;

    void menu();

    void setLength();

    void executeMove();

    void status();

    void setProbePosition(double, double, double);

    void setCustomMotorLength();

    void executeSmallSquare();

    void executeBigSquare();

    void calibrateProbe();

    void getDesiredLengthAndSpeed();

    void addMotorModule(int, int, int, int);

};
