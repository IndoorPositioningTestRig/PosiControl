#include "Controller.h"

using namespace std;

char *port_name = "\\\\.\\COM19";

int main() {
    auto * controller = new Controller(port_name);
    delete controller;
    return 0;
}