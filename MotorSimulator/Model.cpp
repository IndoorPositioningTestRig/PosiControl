#include "Model.h"


Model::Model()
{
	Motors.push_back(MotorModule());
	Motors.push_back(MotorModule());
	Motors.push_back(MotorModule());
	Motors.push_back(MotorModule());
}


Model::~Model()
{
}
