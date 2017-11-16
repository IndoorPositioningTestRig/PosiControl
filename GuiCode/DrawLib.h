#pragma once
#ifndef DRAWLIB_H
#define DRAWLIB_H

#define M_PI 3.14159265359

using namespace std;
#include <gtk/gtk.h>
#include <iostream>
#include <vector>
#include <cairo.h>
#include <gtk/gtk.h>

struct dl_Point2d{
  int x, y;
};
struct dl_Color{
  int r,g,b;
};

struct dl_Line2d{
  dl_Point2d startPoint, endPoint;
  dl_Color color;
  double thickness;
};

struct dl_Rectangle2d{
  dl_Point2d startPoint, endPoint;
  dl_Color color;
  double thickness;
};

struct dl_Circle2d{
  dl_Point2d point;
  dl_Color color;
  int radius;
};

struct dl_WindowSettings {
    int width;
    int height;
};

extern vector<dl_Line2d> dl_lines2D;
extern vector<dl_Rectangle2d> dl_rectangles2D;
extern vector<dl_Circle2d> dl_circles2D;

void dl_CreateWindow(int width, int height);

dl_Color dl_GetColor(int r, int g, int b);
dl_Point2d dl_GetPoint(int x, int y);
dl_Circle2d dl_GetCircle(int x, int y, int radius, dl_Color &color);

int dl_AddLine(dl_Line2d &line);
int dl_AddRectangle(dl_Rectangle2d &rectangle);
int dl_AddCircle(dl_Circle2d &circle);

void dl_RefreshScreen();
void dl_ClearScreen();

#endif
