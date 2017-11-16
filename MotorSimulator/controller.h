#pragma once


#include <string>
#include <vector>
#include "motor_module.h"

class motor_module;

class controller {
public:
    controller();

    void set_desired_probe_position(double x, double y);

    std::string get_position();

    std::string get_desired_position();

private:
    std::vector<motor_module *> Motors;
};