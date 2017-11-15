#pragma once

#include "controller.h"
#include "motor_module_simulator.h"

class communication_handler {
public:
    communication_handler(controller *c);
private:
    motor_module_simulator * motorModuleSimulator;
    controller * Controller;
};
