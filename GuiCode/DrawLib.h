#pragma once
#ifndef DRAWLIB_H
#define DRAWLIB_H
using namespace std;
#include <gtk/gtk.h>
#include <iostream>
#include <vector>
#include <cairo.h>
#include <gtk/gtk.h>

struct dl_LineSettings{
  double thickness;
  int startX, startY, endX, endY, r,g,b;
};

struct dl_WindowSettings {
    int width;
    int height;
};


void dl_CreateWindow(int width, int height);
void dl_DrawLine(dl_LineSettings line);

#endif
