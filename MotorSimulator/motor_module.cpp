#include "motor_module.h"

motor_module::motor_module(double x, double y, controller *c) {
    current_length = 0;
    desired_length = 0;
    this->position[0] = x;
    this->position[1] = y;
    this->&communicationHandler = communication_handler(c);
}