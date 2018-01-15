#pragma once

#include <thread>

class MotorModule {
public:
    MotorModule(int, int, int, int);

    void setLength(int length) {
        this->length = length;
    }

    void setDesiredLength(int length) {
        this->desiredLength = length;
    }

    void setSpeed(int speed) {
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

    int getLength() const {
        return length;
    }

private:
    int id;
    int desiredLength;
    int length;
    int speed;
    int position[3];
};
