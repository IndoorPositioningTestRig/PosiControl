#include <thread>
#include <iostream>
#include "motor_module_simulator.h"

motor_module_simulator::motor_module_simulator(communication_handler *c) {
    this->CommunicationHandler = c;
    this->isRunning = true;
    std::thread thread(runSim);
}

void motor_module_simulator::runSim() {
    while (this->isRunning) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Hello motor here" << std::endl;
    }
}
