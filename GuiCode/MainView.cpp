#include "MainView.h"

int startx[] =  	{100,400,400,100,100,150,450,450,400};
int starty[] = 		{100,100,400,400,100, 75, 75,375,100};
int endx[] = 		{400,400,100,100,150,450,450,400,450};
int endy[] =		{100,400,400,100, 75, 75,375,400, 75};
int thickness[] = 	{  5,  5,  5,  5,  5,  5,  5,  5,  5}; 

void startGui(int width, int height)
{
	unsigned int i;
	for(i = 0; i < 9; i++){
		dl_LineSettings line;
		line.r = 0; line.g = 0; line.b = 0; line.thickness = thickness[i];
		line.startX = startx[i]; line.startY = starty[i]; line.endX = endx[i]; line.endY = endy[i];
		dl_DrawLine(line);
	}
	dl_CreateWindow(width, height);
	cout << "done creating \n";
	
}
