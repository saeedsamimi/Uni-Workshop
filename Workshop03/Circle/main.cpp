// workshop03 Q1
// Created by SaEeD on 3/8/2024.
// main.cpp and main function

#include "Circle.h"
#include <iostream>

using std::cout, std::endl, std::cin, std::boolalpha;

void printPerimeterAndArea(const Circle &, int);

int main() {
  // Define Circles
  Circle circle1(6.1), circle2(7), circle3(3.8);
  // Print P and A
  printPerimeterAndArea(circle1, 1);
  printPerimeterAndArea(circle2, 2);
  printPerimeterAndArea(circle3, 3);
  // Print the Comparators
  cout << "Circle1 > Circle2: " << boolalpha << Circle::compare(circle1, circle2) << endl;
  cout << "Circle2 > Circle3: " << boolalpha << Circle::compare(circle2, circle3) << endl;
  cout << "Circle1 > Circle3: " << boolalpha << Circle::compare(circle1, circle3) << endl;
  return 0;
}

void printPerimeterAndArea(const Circle &c, int index) {
  cout << "Circle"
       << index << ":\n"
       << "Area is: " << c.Area()
       << " & The Perimeter is: " << c.Perimeter() << endl;
}
