#pragma once
#include "vector"
#include "MotorModule.h"

class Model
{
public:
	std::vector<MotorModule> Motors;
	Model();
	~Model();
};
