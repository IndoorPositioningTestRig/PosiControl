#include "Controller.h"
#include <cmath>


Controller::Controller()
{
	model = Model();
}


Controller::~Controller()
{
}

void Controller::set_probe_position(double x, double y)
{
	for (int i = 0; i < model.Motors.size(); i++)
	{
		MotorModule* motor_module = &model.Motors.at(i);
		motor_module->set_desired_length(sqrt(pow(motor_module->get_x() - x, 2) + pow(motor_module->get_y() - y, 2)));
	}
}
