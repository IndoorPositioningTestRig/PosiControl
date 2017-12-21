#include "Controller.h"
#include "RS485/CommunicationHandler.h"

using namespace std;

char *port_name = "\\\\.\\COM11";

int main() {
    Controller controller(port_name);
    return 0;
}