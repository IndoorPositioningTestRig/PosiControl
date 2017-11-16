#include <cmath>
#include <string>
#include <iostream>
#include <thread>

#include "controller.h"


controller::controller() {
    std::cout << "----- Motor simulator -----" << std::endl;
    communication_handler c1 = communication_handler(1, this);
    //communication_handler c2 = communication_handler(2, this);
    //communication_handler c3 = communication_handler(3, this);
    //communication_handler c4 = communication_handler(4, this);
    motor_module m1 = motor_module(0, 0, this, &c1);
    //motor_module m2 = motor_module(5, 0, this, &c2);
    //motor_module m3 = motor_module(5, 5, this, &c3);
    //motor_module m4 = motor_module(0, 5, this, &c4);
    this->Motors.emplace_back(&m1);
    //this->Motors.emplace_back(&m2);
    //this->Motors.emplace_back(&m3);
    //this->Motors.emplace_back(&m4);
    set_desired_probe_position(3, 4);
    std::cout << get_desired_position() << std::endl;
    while (true) {
        //std::this_thread::sleep_for(std::chrono::seconds(1));
        //std::cout << "--------" << std::endl;
    }
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
    for (motor_module *Motor: this->Motors) {
        Motor->desired_length = sqrt(pow(Motor->position[0] - x, 2) + pow(Motor->position[1] - y, 2));
        Motor->CommunicationHandler->moduleSimulator->setDesiredLength(Motor->desired_length);
    }
}

std::string controller::get_position() {
    std::string info;
    for (motor_module *Motor: this->Motors) {
        Motor->current_length = Motor->CommunicationHandler->moduleSimulator->getLength();
        info += std::to_string(Motor->CommunicationHandler->moduleSimulator->getLength());
        info += '\n';
    }
    return info;
}

std::string controller::get_desired_position() {
    std::string info;
    for (motor_module *Motor: this->Motors) {
        info += std::to_string(Motor->desired_length);
        info += '\n';
    }
    return info;
}
