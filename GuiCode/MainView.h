#pragma once

#ifndef MAINVIEW_H
#define MAINVIEW_H

using namespace std;

#include <vector>
#include <X11/Xlib.h>
#include <unistd.h>
#include "DrawLib.h" 
#include <iostream>

/*
 * Function to start gui method call this function in a thread, because this method never ends 
 * Screen starts maximized
 */
void startGui();

void plotPoint(vector<double> & motors);
#endif