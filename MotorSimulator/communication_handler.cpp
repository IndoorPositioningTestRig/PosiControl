#include "communication_handler.h"

communication_handler::communication_handler(int id, controller *c) {
    this->Controller = c;
    motor_module_simulator module_simulator = motor_module_simulator(id, this);
    this->moduleSimulator = &module_simulator;
}
