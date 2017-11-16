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

    void setProbePosition(double x, double y);

private:
    double probePosition[2];
    std::vector<MotorModuleSimulator *> motors;
};
