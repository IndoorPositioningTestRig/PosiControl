#pragma once

#include <string>
#include "../Model/model.h"

class controller {
public:
    controller();

    void set_desired_probe_position(double x, double y);

    std::string get_position();
    std::string get_desired_position();

private:
    model Model;
};