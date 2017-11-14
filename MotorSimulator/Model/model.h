#pragma once

#include "vector"
#include "motor_module.h"

class model {
public:
    model();

    std::vector<motor_module> Motors;
};
