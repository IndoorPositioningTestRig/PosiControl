#pragma once

#ifndef MAINVIEW_H
#define MAINVIEW_H

using namespace std;

#include <vector>
#include <X11/Xlib.h>
#include <unistd.h>
#include "DrawLib.h" 
#include <iostream>
#include <math.h>

struct Point3d{
	double x,y,z;
};

struct MotorData{
	double radian;
	Point3d motorPoint;
};

/*
 * Function to start gui method call this function in a thread, because this method never ends 
 * Screen starts maximized
 */
void startGui();
void plotPoint(vector<MotorData> & motors);
void cleanScreen();
void initScreen();
#endif