#include <thread>
#include <iostream>
#include <future>
#include "MotorModuleSimulator.h"

motor_module_simulator::~motor_module_simulator() {
    bool is = false;
    this->isRunning = &is;
}

motor_module_simulator::motor_module_simulator(int id, communication_handler *communicationHandler) {
    this->id = &id;
    double desiredLength = 0.0;
    this->desiredLength = &desiredLength;
    this->CommunicationHandler = communicationHandler;
    std::cout << *this->desiredLength << std::endl;
    std::thread thread(&motor_module_simulator::runSim, this);
    thread.detach();
}

void motor_module_simulator::runSim() {

    while (this->isRunning) {
        std::cout << "Thread desired length:" << *this->desiredLength << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        if (*this->length > *this->desiredLength) {
            *this->length = *this->length - 0.00001;
        } else if (*this->length < *this->desiredLength) {
            *this->length = *this->length + 0.00001;
        } else if (*this->length == *this->desiredLength) {
            std::cout << "Done. Length probe " << *this->id << "is: " << *this->length << " desiredLength: "
                      << *this->desiredLength << std::endl;
        } else {
            std::cout << "MOTOR ERROR" << std::endl;
        }
    }
    std::terminate();
}

void motor_module_simulator::setDesiredLength(double length) {
    this->desiredLength = &length;
    std::cout << "Length set: " << *this->desiredLength << std::endl;
}

double motor_module_simulator::getLength() {
    return *this->length;
}


