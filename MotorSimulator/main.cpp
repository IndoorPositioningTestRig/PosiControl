#include <iostream>
#include "Controller/controller.h"

using namespace std;

int main() {
    cout << "----- Motor simulator -----" << endl;
    controller c = controller();
    c.set_probe_position(3, 4);
    cout << "get position" << endl;
    cout << c.get_position() << endl;
    cout << "get desired position" << endl;
    cout << c.get_desired_position() << endl;
    return 0;
}