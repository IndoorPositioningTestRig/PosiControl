#pragma once
#include "Model.h"

class Controller
{
public:
	Controller();
	~Controller();

	void set_probe_position(double x, double y);

private:
	Model model;
};
