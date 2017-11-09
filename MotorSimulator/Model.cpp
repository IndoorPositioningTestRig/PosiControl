#include "Model.h"


Model::Model()
{
	Motors.push_back(MotorModule(0, 0));
	Motors.push_back(MotorModule(5, 0));
	Motors.push_back(MotorModule(5, 5));
	Motors.push_back(MotorModule(0, 5));
}


Model::~Model()
{
}
