cmake_minimum_required(VERSION 3.8)
project(MotorModuleSimulator)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Controller.cpp Controller.h MotorModuleSimulator.cpp MotorModuleSimulator.h RS485/SerialPort.cpp RS485/SerialPort.h RS485/CommunicationHandler.cpp RS485/CommunicationHandler.h)
add_executable(MotorModuleSimulator ${SOURCE_FILES})