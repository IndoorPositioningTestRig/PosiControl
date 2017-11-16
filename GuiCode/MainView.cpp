#include "MainView.h"

//cube points
struct {int x,y;} startPoints[] ={
	{-100,-100},{100,-100},{100,100},{-100,100},{-100,-100},{-75,-150},{125,-150},{125,50},{100,-100}
};

struct{int x,y;} endPoints[] = {
	{100,-100},{100,100},{-100,100},{-100,-100},{-75,-150},{125,-150},{125,50},{100,100},{125,-150}
};

struct { double a1, a2;} motorAngles[] = {
	{M_PI * 1.5	,M_PI *2	}, //angle left bottom
	{M_PI		,M_PI *1.5 	}, //angle right bottom
	{M_PI * 0.5	,M_PI		}, //angle right top
	{M_PI * 2	,M_PI *0.5	}  //angle left top	
}; 

struct viewData{
	dl_Point2d centerPoint;
	int size;
	dl_Color color;
	dl_Rectangle2d rect;

}topViewData, sideViewData;

//color of each circle / motor
dl_Color circleColors[] = {{1,0,0},{0,1,0},{0,0,1},{1,1,0}};

//screen width and height
int centerCubeX,centerCubeY;
int screenWidth, screenHeight;

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
	initScreen();
	plotTopView(motorLengths);
	dl_RefreshScreen();
}

void cleanScreen(){
	dl_ClearScreen();
}

void initScreen(){
	cleanScreen();
	addDefaultCube();
	initTopView();
	initSideView();
	dl_RefreshScreen();
}

//PRIVATE functions
void plotTopView(vector<double> & motorLengths){
	
	double motorLengthsArr[] = {motorLengths[0], motorLengths[1], motorLengths[5], motorLengths[4]};
	int centerX = topViewData.centerPoint.x;
	int centerY = topViewData.centerPoint.y;
	int size = topViewData.size;
	int motorX[] = {centerX - size/2, centerX + size/2, centerX + size/2, centerX - size/2};
	int motorY[] = {centerY + size/2, centerY + size/2, centerY - size/2, centerY - size/2};
	
	struct motorData{int x, y; double r;} motorArr[] = {
		{centerX -size/2, centerY + size/2, motorLengths[0]}, 	//motor 0 (A)
		{centerX +size/2, centerY + size/2, motorLengths[1]},	//motor 1 (B)
		{centerX +size/2, centerY - size/2, motorLengths[5]},  	//motor 5 (F)
		{centerX -size/2, centerY - size/2, motorLengths[4]},  	//motor 4 (E)
	};

	for(int i = 0; i < 4; i ++){
		dl_Circle2d c  = dl_GetCircle(
			motorArr[i].x, 
			motorArr[i].y,
			motorArr[i].r * size,
			motorAngles[i].a1,
			motorAngles[i].a2,
			circleColors[i],
			true);
		dl_AddCircle(c);	
	}	
}

void addDefaultCube(){
	centerCubeX = screenWidth  -200;
	centerCubeY = screenHeight -200;	
	for(int i = 0; i < 9; i++){		
		dl_Point2d startPoint = {startPoints[i].x +centerCubeX,startPoints[i].y +centerCubeY};
		dl_Point2d endPoint = {endPoints[i].x +centerCubeX, endPoints[i].y +centerCubeY}; 
		dl_Color color = {0,0,0};
		dl_Line2d line = {startPoint, endPoint,color, 5};
		dl_AddLine(line);
	}
}

void initTopView(){
	int x = centerCubeX + 25;
	int y = centerCubeY - 375;
	int size = 200;
	dl_Point2d startPoint = dl_GetPoint(x -size /2, y -size /2);
	dl_Point2d endPoint = dl_GetPoint(x + size /2, y +size /2);
	dl_Color color = dl_GetColor(0,0,0);
	dl_Rectangle2d rect = {startPoint,endPoint,color,3};
	dl_AddRectangle(rect);
	topViewData = {dl_GetPoint(x,y), size, color, rect};
}

void initSideView(){
	int x = centerCubeX - 350;
	int y = centerCubeY;
	int size = 200;
	dl_Point2d startPoint = dl_GetPoint(x -size/2, y -size/2);
	dl_Point2d endPoint = dl_GetPoint(x + size/2, y +size/2);
	dl_Color color = dl_GetColor(0,0,0);
	dl_Rectangle2d rect = {startPoint,endPoint,color,3};
	dl_AddRectangle(rect);
	sideViewData = {dl_GetPoint(x,y), size, color, rect};
}

void GetDesktopResolution(int &width, int &height){
	Display* disp = XOpenDisplay(NULL);
	Screen*  scrn = DefaultScreenOfDisplay(disp);
	width= 750;
	height = 750;
	// width = scrn->width;
	// height  = scrn->height;
}
