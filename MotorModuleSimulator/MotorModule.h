#pragma once

#include <thread>

class MotorModule {
public:
    MotorModule(int, int, int, int);

    int getLength() const {
        return length;
    }

    void setLength(int currentLength) {
        this->length = currentLength;
    }

    void setDesiredLength(int lengthToSet) {
        this->desiredLength = lengthToSet;
    }

    void setSpeed(int speed){
        this->speed = speed;
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

    void commandSetLength(int Length, int Speed) {
        setDesiredLength(Length);
        setSpeed(Speed);
    }

private:
    int id = -1;
    int desiredLength = 0;
    int length = 0;
    int speed = 0;
    int position[3] = {0, 0, 0};
};
