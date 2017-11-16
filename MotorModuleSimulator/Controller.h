#pragma once

#include <vector>
#include <iostream>
#include <chrono>
#include <thread>
#include <cmath>
#include "MotorModuleSimulator.h"

class Controller {
public:
    Controller();

    void setProbePosition(double, double, double);

private:
    double probePosition[3];
    std::vector<MotorModuleSimulator *> motors;
};
