#include "MainView.h"

void startGui(int width, int height)
{
	dl_LineSettings line;
	line.r = 0; line.g = 0; line.b = 0; line.thickness = 0.5;
	line.startX = 10; line.startY = 10; line.endX = 200; line.endY = 200;
	dl_DrawLine(line);
	dl_CreateWindow(width, height);
	cout << "done creating \n";
}
