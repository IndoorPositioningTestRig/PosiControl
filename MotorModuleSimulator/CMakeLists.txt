cmake_minimum_required(VERSION 3.8)
project(MotorModuleSimulator)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Controller.cpp Controller.h MotorModuleSimulator.cpp MotorModuleSimulator.h)
add_executable(MotorModuleSimulator ${SOURCE_FILES})