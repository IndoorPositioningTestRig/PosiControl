#include "Controller.h"

using namespace std;

char *port_name = "\\\\.\\COM16";

int main() {
    Controller controller(port_name);
    return 0;
}