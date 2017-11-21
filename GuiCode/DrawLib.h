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
#include <string>
#include <stdio.h>
#include <cstring>

struct dl_Point2d{
  int x, y;
};
struct dl_Color{
  double r,g,b;
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
  double angle1, angle2;
  bool drawCenterPoint;
};

struct dl_WindowSettings {
    int width;
    int height;
};

struct dl_Text2d{
  dl_Point2d point;
  dl_Color color;
  char text[63];
  double size;
};

extern vector<dl_Line2d> dl_lines2D;
extern vector<dl_Rectangle2d> dl_rectangles2D;
extern vector<dl_Circle2d> dl_circles2D;
extern vector<dl_Text2d> dl_texts2D;

void dl_CreateWindow(int width, int height);

dl_Color dl_GetColor(double r, double g, double b);
dl_Point2d dl_GetPoint(int x, int y);
dl_Circle2d dl_GetCircle(int x, int y, int radius, double angle1,double angle2, dl_Color &color, bool drawCenterPoint);
dl_Text2d dl_GetText(int x, int y, double size, dl_Color & color, char text[63]);

int dl_AddLine(dl_Line2d &line);
int dl_AddRectangle(dl_Rectangle2d &rectangle);
int dl_AddCircle(dl_Circle2d &circle);
int dl_AddText(dl_Point2d &startpoint, dl_Color color, string text);

void dl_RefreshScreen();
void dl_ClearScreen();

#endif
