#pragma once


#include "controller.h"
#include "communication_handler.h"

class controller;

class communication_handler;

class motor_module {
public:
    motor_module(double, double, controller *, communication_handler *);

    double current_length;
    double desired_length;

    double position[2];

    controller *Controller;
    communication_handler *CommunicationHandler;
};