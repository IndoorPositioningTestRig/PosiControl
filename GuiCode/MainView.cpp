#include "MainView.h"

//test cube points
int startx[] =  	{-100,100,100,-100,-100,-75,125,125,100};
int starty[] = 		{-100,-100,100,100,-100,-150,-150,50,-100};
int endx[] = 		{100,100,-100,-100,-75,125,125,100,125};
int endy[] =		{-100,100,100,-100, -150, -150,50,100, -150};
int thickness[] = 	{  5,  5,  5,  5,  5,  5,  5,  5,  5}; 

//screen width and height
int screenWidth, screenHeight;

//default lines of interface
vector<dl_Line2d> lines;

//PRIVATE FUNCTIONS:
//Function to get the screen resolution, sets given parameters 
void GetDesktopResolution(int &width, int &height);
void initializeGui();
void addDefaultCube();
void addTopView();
void addSideView();

//PUBLIC FUNCTIONS DECLERATIONS:
void startGui()
{
	GetDesktopResolution(screenWidth, screenHeight);
	initializeGui();
}

void initializeGui(){
	addDefaultCube();
	addTopView();
	addSideView();
	dl_CreateWindow(screenWidth, screenHeight);	
	dl_RefreshScreen();
}

void addDefaultCube()
{
	int centerCubeX = screenWidth  /2;
	int centerCubeY = screenHeight /2;	
	unsigned int i;
	for(i = 0; i < 9; i++){		
		dl_Point2d startPoint, endPoint; 
		startPoint.x = startx[i] +centerCubeX; startPoint.y = starty[i] +centerCubeY;
		endPoint.x = endx[i] +centerCubeX; endPoint.y = endy[i] +centerCubeY;
		dl_Color color;
		color.r = 0; color.g = 0; color.b = 0;
		int thickness = 5;
		dl_Line2d line;
		line.startPoint = startPoint;
		line.endPoint = endPoint;
		line.color = color;
		line.thickness = thickness;
		dl_AddLine(line);
		lines.push_back(line);
	}
}

void addTopView(){
	int x = screenWidth / 2;
	int y = screenHeight / 2 - 350;
	dl_Point2d startPoint = dl_GetPoint(x -100, y -100);
	dl_Point2d endPoint = dl_GetPoint(x + 100, y +100);
	dl_Color color = dl_GetColor(0,0,0);
	dl_Rectangle2d rect;
	rect.startPoint = startPoint;
	rect.endPoint = endPoint;
	rect.color = color;
	rect.thickness = 3;
	rect.id = 0;
	dl_AddRectangle(rect);
}

void addSideView(){
	int x = screenWidth / 2 - 350;
	int y = screenHeight / 2;
	dl_Point2d startPoint = dl_GetPoint(x -100, y -100);
	dl_Point2d endPoint = dl_GetPoint(x + 100, y +100);
	dl_Color color = dl_GetColor(0,0,0);
	dl_Rectangle2d rect;
	rect.startPoint = startPoint;
	rect.endPoint = endPoint;
	rect.color = color;
	rect.thickness = 3;
	rect.id = 0;
	dl_AddRectangle(rect);
}


//PRIVATE FUNCTIONS DECLERATIONS:
void GetDesktopResolution(int &width, int &height)
{
	Display* disp = XOpenDisplay(NULL);
	Screen*  scrn = DefaultScreenOfDisplay(disp);
	width = scrn->width;
	height  = scrn->height;
}
