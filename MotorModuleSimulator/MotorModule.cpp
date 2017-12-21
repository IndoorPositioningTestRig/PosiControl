#include "MotorModule.h"

MotorModule::MotorModule(int id, int x, int y, int z) {
    this->id = id;
    this->length = 0;
    this->desiredLength = 0;
    this->position[0] = x;
    this->position[1] = y;
    this->position[2] = z;
}
