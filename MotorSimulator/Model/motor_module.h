#pragma once

class motor_module {
public:
    motor_module(int x, int y);

    double get_x();
    double get_y();
    double get_current_length();
    double get_desired_length();

    void set_desired_length(double length);

private:
    double current_length;
    double desired_length;

    double current_x;
    double current_y;
};