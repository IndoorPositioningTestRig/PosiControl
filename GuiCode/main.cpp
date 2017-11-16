using namespace std;
#include <iostream>
#include "MainView.h" 
#include <thread>  
#include <unistd.h> 



int main(int argc, char* argv[])
{
	cout << "starting application" << endl;
	cout << "starting gui thread" << endl;
	thread guiThread(startGui);
	//wait 0.1 s for gui
	usleep(100 * 1000);

	//test motors:
	vector<double> motors;
	for(int i = 0; i < 8; i ++)
		motors.push_back(0.7);
	plotPoint(motors);

	// keep program running
	while(1){
		//TODO: Put here some awesome stuff
		usleep( 1000 * 1000);
	}
	return 0;
}