#include "communication_handler.h"

communication_handler::communication_handler(controller * c) {
    this->Controller = c;
    this->&motorModuleSimulator = motor_module_simulator(this);
}
