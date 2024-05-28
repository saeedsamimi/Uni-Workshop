#include "cube.hpp"
#include <iostream>

using std::cout;

int main() {
  cube c1(2.3, 2.1, 5.3);
  cube c2(3.4, 1.2, 6.7);
  // test << operator and + - arithmetic operators
  cout << "cube1 ->" << c1;
  cout << "cube2 ->" << c2;
  cout << "cube1 + cube2 ->" << c1 + c2;
  cout << "cube1 - cube2 ->" << c1 - c2;
  // test caster method
  float test = caster(3, cout);
}