#include "motor_module.h"

motor_module::motor_module(double x, double y, controller *Controller, communication_handler *communicationHandler)
        : Controller(Controller), CommunicationHandler(communicationHandler) {
    current_length = 0;
    desired_length = 0;
    this->position[0] = x;
    this->position[1] = y;
}
