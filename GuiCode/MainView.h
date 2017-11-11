#pragma once

#ifndef MAINVIEW_H
#define MAINVIEW_H

using namespace std;

#include <vector>
#include <X11/Xlib.h>
#include <unistd.h>
#include "DrawLib.h" 

/*
 * Function to start gui method call this function in a thread, because this method never ends 
 * Screen starts maximized
 */
void startGui();

/*
 * Function to draw a default cube in the center gui
 */
void DrawDefaultCube();

#endif