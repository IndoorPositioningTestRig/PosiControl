cmake_minimum_required(VERSION 3.8)
project(MotorSimulator)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Controller/controller.cpp Controller/controller.h Model/model.cpp Model/model.h Model/motor_module.cpp Model/motor_module.h)
add_executable(MotorSimulator ${SOURCE_FILES})