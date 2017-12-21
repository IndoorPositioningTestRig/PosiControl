#pragma once

#include <thread>
#include <iostream>
#include "MotorModule.h"

class MotorModuleSimulator : public MotorModule {
public:
    MotorModuleSimulator(int id, int x, int y, int z) : MotorModule(id, x, y, z) {

    };

    void commandSetLength(int Length, int Speed) {
        setDesiredLength(Length);
        setSpeed(Speed);
    }

    void commandGo() {
        this->simulator = new std::thread(&MotorModuleSimulator::runSim, this);
        this->simulator->detach();
    }

private:
    std::thread* simulator;
    void runSim();
};
