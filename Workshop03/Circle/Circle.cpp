// Workshop03 Q1
// Created by SaEeD on 3/8/2024.
// CIRCLE <Implementation file>

#include <cmath>
#include "Circle.h"

Circle::Circle(double r) : radius(r) {}

Circle::Circle() : Circle(0) {}

double Circle::Area() const {
  // returns PI*r*r
  return M_PI * radius * radius;
}

double Circle::Perimeter() const {
  // returns 2*PI*r
  return 2 * M_PI * radius;
}

// returns cir1 > cir2
bool Circle::compare(Circle &cir1, Circle &cir2) {
  return cir1.radius > cir2.radius;
}