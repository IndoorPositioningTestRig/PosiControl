#pragma once

#include "communication_handler.h"

class motor_module_simulator {
public:
    motor_module_simulator(communication_handler *c);

    void runSim();

private:
    communication_handler *CommunicationHandler;
    bool isRunning;
    int length;
};
