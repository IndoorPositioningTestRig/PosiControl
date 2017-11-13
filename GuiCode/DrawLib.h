#pragma once
#ifndef DRAWLIB_H
#define DRAWLIB_H

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
  int id;
};

struct dl_Rectangle2d{
  dl_Point2d startPoint, endPoint;
  dl_Color color;
  double thickness;
  int id;
};

struct dl_WindowSettings {
    int width;
    int height;
};

extern vector<dl_Line2d> dl_lines2D;
extern vector<dl_Rectangle2d> dl_rectangles2D;

void dl_CreateWindow(int width, int height);
dl_Color dl_GetColor(int r, int g, int b);
dl_Point2d dl_GetPoint(int x, int y);
void dl_AddLine(dl_Line2d &line);
void dl_AddRectangle(dl_Rectangle2d &rectangle);
void dl_DrawNewLine(dl_Point2d &startPoint, dl_Point2d &endPoint, dl_Color &color, int thickness);
void dl_RefreshScreen();
void dl_ClearScreen();

#endif
