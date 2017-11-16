#pragma once

#include <thread>
#include <iostream>

class MotorModuleSimulator {
public:
    MotorModuleSimulator(int, int, int);


    void setLength(double newLength) {
        this->length = newLength;
    }

    double getLength() const {
        return length;
    }

    void setDesiredLength(double Length) {
        desiredLength = Length;
        std::thread thread(&MotorModuleSimulator::runSim, this);
        thread.detach();
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

private:
    int id;
    double desiredLength;
    double length;
    int position[2];

    void runSim();

};
