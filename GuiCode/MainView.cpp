#include "MainView.h"

//cube points
struct {int x,y;} startPoints[] ={
	{-100,-100},{100,-100},{100,100},{-100,100},{-100,-100},{-75,-150},{125,-150},{125,50},{100,-100}
};

struct{int x,y;} endPoints[] = {
	{100,-100},{100,100},{-100,100},{-100,-100},{-75,-150},{125,-150},{125,50},{100,100},{125,-150}
};


struct viewData{
	dl_Point2d centerPoint;
	int size;
	dl_Color color;
	dl_Rectangle2d rect;

}topViewData, sideViewData;

struct { double a1, a2;} motorAngles[] = {
	{M_PI * 1.5	,M_PI *2	}, //angle left bottom
	{M_PI		,M_PI *1.5 	}, //angle right bottom
	{M_PI * 0.5	,M_PI		}, //angle right top
	{M_PI * 2	,M_PI *0.5	}  //angle left top	
}; 

//color of each circle / motor
dl_Color circleColors[] = {{1,0,0},{0,1,0},{0,0,1},{1,1,0}};

//screen width and height
int centerCubeX,centerCubeY;
int screenWidth, screenHeight;

//PRIVATE FUNCTIONS:
//Function to get the screen resolution, sets given parameters 
Point3d calculatePoint(vector<MotorData> & radians);
void plotTopView(Point3d probePoint);
void plotSideView(Point3d probepoint);
void addDefaultCube();
void initTopView();
void initSideView();
void GetDesktopResolution(int &width, int &height);
int getMotorIndex(Point3d point, vector<MotorData> & motors);
void writeProbeInfo(vector<MotorData> & motors, Point3d probePoint);

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

void plotPoint(vector<MotorData> & motors){
	Point3d point = calculatePoint(motors);
	initScreen();
	plotTopView(point);
	plotSideView(point);
	writeProbeInfo(motors, point);
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
Point3d calculatePoint(vector<MotorData> & motors){
	MotorData centerMotor = motors[getMotorIndex({0,0,0}, motors)];
	MotorData xMotor = motors[getMotorIndex({1,0,0}, motors)];
	MotorData yMotor =motors[getMotorIndex({0,1,0}, motors)];
	MotorData zMotor = motors[getMotorIndex({0,0,1}, motors)];
	Point3d probePoint;
	//calculate x:
	int amountOfX = xMotor.motorPoint.x * -2;
	double xValue = (xMotor.radian - centerMotor.radian) - pow(xMotor.motorPoint.x,2);
	probePoint.x = xValue / amountOfX;

	//calculate y:
	int amountOfY = yMotor.motorPoint.y * -2;
	double yValue = (yMotor.radian - centerMotor.radian) - pow(yMotor.motorPoint.y, 2);
	probePoint.y = yValue / amountOfY;

	//calculate z:
	int amountOfz = zMotor.motorPoint.z * -2;
	double zValue = (zMotor.radian - centerMotor.radian) - pow(zMotor.motorPoint.z, 2);
	probePoint.z = zValue / amountOfz;
	
	//cout << "probepoint: x:" <<  probePoint.x << " y:" << probePoint.y << " z:" << probePoint.z << endl;
	return probePoint;
}

void plotTopView(Point3d probePoint){
	int cubeSize = 1;
	vector<double> motorLengths;
	motorLengths.push_back(sqrt(pow(probePoint.x,2)+ pow(probePoint.z,2)));					//Motor A
	motorLengths.push_back(sqrt(pow(cubeSize - probePoint.x,2)+ pow(probePoint.z,2)));			//Motor B 
	motorLengths.push_back(sqrt(pow(cubeSize - probePoint.x,2)+ pow(cubeSize - probePoint.z,2)));	//Motor F
	motorLengths.push_back(sqrt(pow(probePoint.x,2)+ pow(cubeSize -probePoint.z,2)));			//Motor E
	int centerX = topViewData.centerPoint.x;
	int centerY = topViewData.centerPoint.y;
	int size = topViewData.size;
	int motorX[] = {centerX - size/2, centerX + size/2, centerX + size/2, centerX - size/2};
	int motorY[] = {centerY + size/2, centerY + size/2, centerY - size/2, centerY - size/2};
	
	struct motorData{int x, y; double r;} motorArr[] = {
		{centerX -size/2, centerY + size/2, motorLengths[0]}, 	//motor 0 (A)
		{centerX +size/2, centerY + size/2, motorLengths[1]},	//motor 1 (B)
		{centerX +size/2, centerY - size/2, motorLengths[2]},  	//motor 5 (F)
		{centerX -size/2, centerY - size/2, motorLengths[3]},  	//motor 4 (E)
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

void plotSideView(Point3d probePoint){
	int cubeSize = 1;
	vector<double> motorLengths;
	motorLengths.push_back(sqrt(pow(cubeSize - probePoint.z,2)+ pow(probePoint.y,2)));						//Motor H
	motorLengths.push_back(sqrt(pow(probePoint.z,2)+ pow(probePoint.y,2)));									//Motor D
	motorLengths.push_back(sqrt(pow(probePoint.z,2)+ pow(cubeSize - probePoint.y,2)));						//Motor A
	motorLengths.push_back(sqrt(pow(cubeSize -probePoint.z,2)+ pow(cubeSize -probePoint.y,2)));				//Motor E
	int centerX = sideViewData.centerPoint.x;
	int centerY = sideViewData.centerPoint.y;
	int size = sideViewData.size;
	int motorX[] = {centerX - size/2, centerX + size/2, centerX + size/2, centerX - size/2};
	int motorY[] = {centerY + size/2, centerY + size/2, centerY - size/2, centerY - size/2};
	
	struct motorData{int x, y; double r;} motorArr[] = {
		{centerX -size/2, centerY + size/2, motorLengths[0]}, 	//motor 0 (H)
		{centerX +size/2, centerY + size/2, motorLengths[1]},	//motor 1 (D)
		{centerX +size/2, centerY - size/2, motorLengths[2]},  	//motor 5 (A)
		{centerX -size/2, centerY - size/2, motorLengths[3]},  	//motor 4 (E)
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

void writeProbeInfo(vector<MotorData> & motors, Point3d probePoint){
	
	dl_Color color = {1,0,0};
	dl_Text2d title = dl_GetText(50,50,3,color,"PosiControl Simulator");
	dl_texts2D.push_back(title);
	color = {0,0,0};
	dl_Text2d info1 = dl_GetText(50,60,1,color,"XYZ Positie probe: ");
	dl_texts2D.push_back(info1);
	stringstream  strs;
	strs << "x: " << probePoint.x << " y: " << probePoint.y << " z: " << probePoint.z;
	std::string s = strs.str();
	char* p = const_cast<char*>(s.c_str());
	dl_Text2d info2 = dl_GetText(50,70,1,color,p);
	dl_texts2D.push_back(info2);	
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
	dl_Text2d text = dl_GetText(x-size/2 +25, y-size/2 - 20,2, color, "Bovenaanzicht:");
	text.point = {x-size/2 +25, y-size/2 - 20};
	dl_texts2D.push_back(text);
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
	dl_Text2d text = dl_GetText(x-size/2 +25, y-size/2 - 20,2, color, "Zijaanzicht:");
	dl_texts2D.push_back(text);
}

void GetDesktopResolution(int &width, int &height){
	Display* disp = XOpenDisplay(NULL);
	Screen*  scrn = DefaultScreenOfDisplay(disp);
	width= 750;
	height = 750;
	// width = scrn->width;
	// height  = scrn->height;
}

//return the motorindex with given motorpoint
//this function checks on 0 and !=0
int getMotorIndex(Point3d point, vector<MotorData> & motors){
	for(int i = 0; i < motors.size(); i ++){
		if((point.x == 0) == (motors[i].motorPoint.x == 0))
			if((point.y == 0) == (motors[i].motorPoint.y == 0))
				if((point.z == 0) == (motors[i].motorPoint.z == 0))
					return i;
	}
	cout <<"no motor found" << endl;
	return -1;
}
