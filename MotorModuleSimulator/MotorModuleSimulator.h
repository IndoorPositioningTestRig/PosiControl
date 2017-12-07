#pragma once

#include <thread>
#include <iostream>

class MotorModuleSimulator {
public:
    MotorModuleSimulator(int, int, int, int);

    int getLength() const {
        return length;
    }

    void setLength(int currentLength) {
        this->length = currentLength;
    }

/*
 * Length in mm
 * Speed in mm/s
 * */
    void commandSetLength(int Length, int Speed) {
        this->desiredLength = Length;
        this->speed = Speed;
    }

    void commandGo() {
        this->simulator = new std::thread(&MotorModuleSimulator::runSim, this);
        this->simulator->detach();
    }

    int getDesiredLength() const {
        return desiredLength;
    }

    int getId() const {
        return id;
    }

    int getX() const {
        return position[0];
    }

    int getY() const {
        return position[1];
    }

    int getZ() const {
        return position[2];
    }

    int getSpeed() const {
        return speed;
    }

    std::thread *simulator;

private:
    int id = -1;
    int desiredLength = 0;
    int length = 0;
    int speed = 0;
    int position[3] = {0, 0, 0};

    void runSim();

};
