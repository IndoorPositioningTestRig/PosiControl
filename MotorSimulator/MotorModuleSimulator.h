#pragma once

#include "communication_handler.h"

class communication_handler;

class motor_module_simulator {
public:
    motor_module_simulator(int, communication_handler *);

    ~motor_module_simulator();

    void runSim();
    void setDesiredLength(double);
    double getLength();

private:
    communication_handler *CommunicationHandler;
    bool *isRunning;
    double *length;
    double *desiredLength;
    int *id;
};
