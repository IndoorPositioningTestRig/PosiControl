#pragma once

#include "communication_handler.h"

class motor_module {
public:
    motor_module(double x, double y, controller *c);

    double current_length;
    double desired_length;

    double position[2];
    communication_handler * communicationHandler;
};