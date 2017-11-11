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
	
	//draw cube in mainview.cpp
	DrawDefaultCube();

	// keep program running
	while(1){
		//TODO: Put here some awesome stuff
		usleep( 1000 * 1000);
	}
	return 0;
}