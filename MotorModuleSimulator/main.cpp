#include "Controller.h"
#include "RS485/CommunicationHandler.h"

using namespace std;

char * port_name = "\\\\.\\COM15";

int main() {
//    Controller controller;

    CommunicationHandler communicationHandler(port_name);
    communicationHandler.executeMove();
    communicationHandler.setLength(1, 100, 100);
    return 0;
}