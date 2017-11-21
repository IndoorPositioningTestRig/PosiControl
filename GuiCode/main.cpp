using namespace std;
#include <iostream>
#include "MainView.h" 
#include <thread>  
#include <unistd.h> 
#include <vector>


int main(int argc, char* argv[])
{
	cout << "starting application" << endl;
	cout << "starting gui thread" << endl;
	thread guiThread(startGui);
	//wait 0.1 s for gui
	usleep(100 * 1000);

	Point3d motorPoints[] = {
		//{x,y,z} coordinates
		{ 0,1,0 }, //motor A 
		{ 1,1,0 }, //motor B 
		{ 1,0,0 }, //motor C
		{ 0,0,0 }, //motor D
		{ 0,1,1 }, //motor E
		{ 1,1,1 }, //motor F
		{ 1,0,1 }, //motor G
		{ 0,0,1 }  //motor H
	};
		
	// double lengths2[] = {1.131,0.825,0,0,0.825,0.283,0,0};

	// double lengths[] = {0.866,0.866,0.866,0.866,0.866,0.866,0.866,0.866};
	
	// vector<MotorData> motorsData;
	// for(int i = 0; i < 8; i ++){
	// 	motorsData.push_back({lengths[i], motorPoints[i]});
	// }



	

	// keep program running
	while(1){
		double lengths2[] = {0.433,0.829,1.090,0.356,0.356,1.09,1.299,1.09};

		double lengths[] = {0.866,0.866,0.866,0.866,0.866,0.866,0.866,0.866};
		
		vector<MotorData> motorsData;
		for(int i = 0; i < 8; i ++){
			motorsData.push_back({lengths[i], motorPoints[i]});
		}
		plotPoint(motorsData);

		usleep( 1000 * 1000);
		
		motorsData.clear();
		for(int i = 0; i < 8; i ++){
			motorsData.push_back({lengths2[i], motorPoints[i]});
		}
		plotPoint(motorsData);
		usleep(1000 * 1000);

	}
	return 0;
}