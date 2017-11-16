cmake_minimum_required(VERSION 3.8)
project(MotorSimulator)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp controller.cpp controller.h motor_module.cpp motor_module.h communication_handler.cpp communication_handler.h MotorModuleSimulator.cpp MotorModuleSimulator.h)
add_executable(MotorSimulator ${SOURCE_FILES})