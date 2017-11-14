#include <cmath>
#include <string>
#include "controller.h"

controller::controller() {
    this->Model = model();
}

void controller::set_probe_position(double x, double y) {
    for (motor_module &Motor : this->Model.Motors) {
        motor_module *motor_module = &Motor;
        motor_module->set_desired_length(sqrt(pow(motor_module->get_x() - x, 2) + pow(motor_module->get_y() - y, 2)));
    }
}

std::string controller::get_position() {
    std::string info;
    for (motor_module &Motor : this->Model.Motors) {
        info += std::to_string(Motor.get_current_length());
        info += '\n';
    }
    return info;
}

std::string controller::get_desired_position() {
    std::string info;
    for (motor_module &Motor : this->Model.Motors) {
        info += std::to_string(Motor.get_desired_length());
        info += '\n';
    }
    return info;
}


