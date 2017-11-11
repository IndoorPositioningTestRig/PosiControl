#include "MainView.h"

//test cube points
int startx[] =  	{100,400,400,100,100,150,450,450,400};
int starty[] = 		{100,100,400,400,100, 75, 75,375,100};
int endx[] = 		{400,400,100,100,150,450,450,400,450};
int endy[] =		{100,400,400,100, 75, 75,375,400, 75};
int thickness[] = 	{  5,  5,  5,  5,  5,  5,  5,  5,  5}; 

//screen width and height
int screenWidth, screenHeight;

//PRIVATE FUNCTIONS:
//Function to get the screen resolution, sets given parameters 
void GetDesktopResolution(int &width, int &height);

//PUBLIC FUNCTIONS DECLERATIONS:
void startGui()
{
	screenWidth = screenHeight = 0;
	GetDesktopResolution(screenWidth, screenHeight);
	dl_CreateWindow(screenWidth, screenHeight);	
}

void DrawDefaultCube()
{
	unsigned int i;
	for(i = 0; i < 9; i++){
		usleep( 1000 * 1000);
		dl_LineSettings line;
		line.r = 0; line.g = 0; line.b = 0; line.thickness = thickness[i];
		line.startX = startx[i]; line.startY = starty[i]; line.endX = endx[i]; line.endY = endy[i];
		dl_DrawLine(line);
	}
}


//PRIVATE FUNCTIONS DECLERATIONS:
void GetDesktopResolution(int &width, int &height)
{
	Display* disp = XOpenDisplay(NULL);
	Screen*  scrn = DefaultScreenOfDisplay(disp);
	width = scrn->width;
	height  = scrn->height;
}
