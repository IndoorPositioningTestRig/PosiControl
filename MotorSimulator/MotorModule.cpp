#include "MotorModule.h"


MotorModule::MotorModule(int x, int y)
{
	current_length = 0;
	desired_length = 0;
	current_x = x;
	current_y = y;
}


MotorModule::~MotorModule()
{
}

int MotorModule::get_x() const
{
	return current_x;
}

int MotorModule::get_y() const
{
	return current_y;
}

void MotorModule::set_desired_length(double length)
{
	desired_length = length;
}
