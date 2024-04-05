#include <iostream>
#include <random>
#include "Circle.h"

using namespace std;

[[maybe_unused]] int boundedRandom(int, int);

int main() {
  Circle circles[100];
  for (int i = 0; i < 100; i++)
    circles[i].setRadius(i + 1);
  Circle c(boundedRandom(10, 1000));
  cout << "C: " << c << endl;
  c.addAll(circles, 100);
  cout << "C after adding all circles 1...100: " << c << endl;
  // testing decomposition
  Circle b(42686253);
  cout << "Decomposition of B: " << b << " is: " << endl;
  Circle *circlesOut = nullptr;
  int count = b.decompose(circlesOut);
  for(int i = 0;i<count;i++)
    cout << circlesOut[i] << endl;
  delete[] circlesOut;// deleting nullptr not effected
  return 0;
}

int boundedRandom(int s, int e) {
  srand(time(nullptr));
  return (rand() % (s - e)) + s;
}