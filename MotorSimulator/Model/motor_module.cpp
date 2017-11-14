#include "motor_module.h"

motor_module::motor_module(int x, int y) {
    current_length = 0;
    desired_length = 0;
    current_x = x;
    current_y = y;
}

double motor_module::get_x() {
    return current_x;
}

double motor_module::get_y() {
    return current_y;
}

void motor_module::set_desired_length(double length) {
    desired_length = length;
}

double motor_module::get_current_length() {
    return this->current_length;
}

double motor_module::get_desired_length() {
    return this->desired_length;
}
