#pragma once
class MotorModule
{
public:
	MotorModule(int x, int y);
	~MotorModule();

	int get_x() const;
	int get_y() const;
	void set_desired_length(double length);
private:
	double current_length;
	double desired_length;

	double current_x;
	double current_y;
};
