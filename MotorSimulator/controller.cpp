#include <cmath>
#include <string>
#include <iostream>

#include "controller.h"

using namespace std;

controller::controller() {
    cout << "----- Motor simulator -----" << endl;
    std::vector<motor_module> Motors;
    this->Motors.emplace_back(0, 0, this);
    this->Motors.emplace_back(5, 0, this);
    this->Motors.emplace_back(5, 5, this);
    this->Motors.emplace_back(0, 5, this);
    set_desired_probe_position(3, 4);
    /*
        de applicatie moet voor een coordinaat een desired length voor elke motor bepalen.
            1. Locatie wordt ingevoerd
            2. Desired length wordt berekend
            3. Desired length wordt doorgestuurd naar de modules
	            de modules berekenen vervolgens zelf hoe snel ze moeten bewegen
            4. wachten op reacties
    */
}

void controller::set_desired_probe_position(double x, double y) {
    for (motor_module &Motor : this->Motors) {
        motor_module *motor_module = &Motor;
        motor_module->desired_length = sqrt(
                pow(motor_module->position[0] - x, 2) + pow(motor_module->position[1] - y, 2));
    }
}

string controller::get_position() {
    string info;
    for (motor_module &Motor : this->Motors) {
        info += to_string(Motor.current_length);
        info += '\n';
    }
    return info;
}

string controller::get_desired_position() {
    string info;
    for (motor_module &Motor : this->Motors) {
        info += to_string(Motor.desired_length);
        info += '\n';
    }
    return info;
}


