#include "MainView.h"

//test cube points
int startx[] =  	{-100,100,100,-100,-100,-75,125,125,100};
int starty[] = 		{-100,-100,100,100,-100,-150,-150,50,-100};
int endx[] = 		{100,100,-100,-100,-75,125,125,100,125};
int endy[] =		{-100,100,100,-100, -150, -150,50,100, -150};
int thickness[] = 	{  5,  5,  5,  5,  5,  5,  5,  5,  5}; 

dl_Color circleColors[] = {{255,0,0},{0,255,0},{0,0,255},{255,255,0}};

//screen width and height
int screenWidth, screenHeight;

struct {
	dl_Point2d centerPoint, probePoint;
	int size;
	dl_Color color;
	dl_Rectangle2d rect;

}topViewData, sideViewData;


//PRIVATE FUNCTIONS:
//Function to get the screen resolution, sets given parameters 
void GetDesktopResolution(int &width, int &height);
void addDefaultCube();

void plotTopView(vector<double> & motorLengths);
void initTopView();
void initSideView();

//PUBLIC FUNCTIONS 
void startGui()
{
	GetDesktopResolution(screenWidth, screenHeight);
	addDefaultCube();
	initTopView();
	initSideView();
	dl_CreateWindow(screenWidth, screenHeight);	
	dl_RefreshScreen();
}

void plotPoint(vector<double> & motorLengths){
	plotTopView(motorLengths);
	dl_RefreshScreen();
}

//PRIVATE functions

void plotTopView(vector<double> & motorLengths){
	double motorLengthsArr[] = {motorLengths[0], motorLengths[1], motorLengths[5], motorLengths[4]};
	int centerX = topViewData.centerPoint.x;
	int centerY = topViewData.centerPoint.y;
	int size = topViewData.size;
	int motorX[] = {centerX  - size/2, centerX + size/2, centerX + size/2, centerX - size/2};
	int motorY[] = {centerY  - size/2, centerY - size/2, centerY + size/2, centerY + size/2};
	
	for(int i = 0; i < 4; i ++){
		cout << "adding motor " << i << endl; 
		cout << "\t x:" << motorX[i] << " y:" << motorY[i] << endl;
		dl_Circle2d c  = dl_GetCircle(
			motorX[i], 
			motorY[i],
			motorLengthsArr[i] * size, 
			circleColors[i]);
		dl_AddCircle(c);	
	}	
}

void addDefaultCube(){
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
	}
}

void initTopView(){
	int x = screenWidth / 2 + 25;
	int y = screenHeight / 2 - 375;
	int size = 200;
	dl_Point2d startPoint = dl_GetPoint(x -size /2, y -size /2);
	dl_Point2d endPoint = dl_GetPoint(x + size /2, y +size /2);
	dl_Color color = dl_GetColor(0,0,0);
	dl_Rectangle2d rect;
	rect.startPoint = startPoint;
	rect.endPoint = endPoint;
	rect.color = color;
	rect.thickness = 3;
	dl_AddRectangle(rect);
	topViewData.centerPoint = dl_GetPoint(x,y);
	topViewData.size = size;
	topViewData.color = color;
	topViewData.rect = rect;
}

void initSideView(){
	int x = screenWidth / 2 - 350;
	int y = screenHeight / 2;
	int size = 200;
	dl_Point2d startPoint = dl_GetPoint(x -size/2, y -size/2);
	dl_Point2d endPoint = dl_GetPoint(x + size/2, y +size/2);
	dl_Color color = dl_GetColor(0,0,0);
	dl_Rectangle2d rect;
	rect.startPoint = startPoint;
	rect.endPoint = endPoint;
	rect.color = color;
	rect.thickness = 3;
	dl_AddRectangle(rect);
	sideViewData.centerPoint = dl_GetPoint(x,y);
	sideViewData.size = size;
	sideViewData.color = color;
	sideViewData.rect = rect;
}

void GetDesktopResolution(int &width, int &height){
	Display* disp = XOpenDisplay(NULL);
	Screen*  scrn = DefaultScreenOfDisplay(disp);
	width = scrn->width;
	height  = scrn->height;
}
