#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <cstring>

int main() {
  int16_t i_test = 0;
  double d_test = 23342.23324;

  i_test = (int16_t)d_test;

  std::cout << INT16_MAX << ", " << i_test << std::endl;

  return 0;
}