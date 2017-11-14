#include <cmath>
#include <string>
#include <iostream>
#include "controller.h"

using namespace std;

controller::controller() {
    cout << "----- Motor simulator -----" << endl;
    this->Model = model();
    set_desired_probe_position(3, 4);
    cout << "get position" << endl;
    cout << get_position() << endl;
    cout << "get desired position" << endl;
    cout << get_desired_position() << endl;
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
    for (motor_module &Motor : this->Model.Motors) {
        motor_module *motor_module = &Motor;
        motor_module->set_desired_length(sqrt(pow(motor_module->get_x() - x, 2) + pow(motor_module->get_y() - y, 2)));
    }
}

string controller::get_position() {
    string info;
    for (motor_module &Motor : this->Model.Motors) {
        info += to_string(Motor.get_current_length());
        info += '\n';
    }
    return info;
}

string controller::get_desired_position() {
    string info;
    for (motor_module &Motor : this->Model.Motors) {
        info += to_string(Motor.get_desired_length());
        info += '\n';
    }
    return info;
}


