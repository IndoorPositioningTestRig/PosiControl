#pragma once

#include <vector>
#include <iostream>
#include <chrono>
#include <thread>
#include <cmath>
#include "RS485/CommunicationHandler.h"

class Controller {
public:
    Controller(char *port_name);

    ~Controller();

    void setProbePosition(double, double, double);

    void addMotorModule(int, int, int, int);

private:
    double probePosition[3];
    std::vector<MotorModule *> motors;
    CommunicationHandler *rs485;
};
