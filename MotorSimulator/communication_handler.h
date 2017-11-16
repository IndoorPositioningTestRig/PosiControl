#pragma once

#include "controller.h"
#include "MotorModuleSimulator.h"

class controller;

class motor_module_simulator;

class communication_handler {
public:
    communication_handler(int id, controller *c);

    motor_module_simulator *moduleSimulator;
private:
    controller *Controller;
};
