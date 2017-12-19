#include "Controller.h"
#include "RS485/SerialPort.h"
#include "RS485/CommunicationHandler.h"

using namespace std;

char *port_name = "\\\\.\\COM15";

//String for incoming data
char *incomingData;

int main() {
//    Controller controller;

    CommunicationHandler communicationHandler;
    communicationHandler.executeMove();
    communicationHandler.setLength(1, 100, 100);
    return 0;
}