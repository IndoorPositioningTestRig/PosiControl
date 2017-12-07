#pragma once

#include <thread>
#include <iostream>

class MotorModuleSimulator {
public:
    MotorModuleSimulator(int, int, int, int);

    void setLength(double newLength) {
        this->length = newLength;
    }

    double getLength() const {
        return length;
    }

    void setDesiredLength(double Length) {
        desiredLength = Length;
    }

    void go(){
        this->simulator = new std::thread(&MotorModuleSimulator::runSim, this);
        this->simulator->detach();
    }

    double getDesiredLength() const {
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
    std::thread* simulator;

private:
    int id = -1;
    double desiredLength = 0;
    double length = 0;
    int position[3] = {0,0,0};

    void runSim();

};
