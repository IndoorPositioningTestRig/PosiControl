#include "Controller.h"
#include "RS485/CommunicationHandler.h"

using namespace std;

char * port_name = "\\\\.\\COM11";

int main() {
//    Controller controller;

    CommunicationHandler communicationHandler(port_name);
    communicationHandler.setLength(1, 100, 100);
    //communicationHandler.executeMove();
    return 0;
}