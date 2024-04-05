#include "Circle.h"
#include <stdexcept>

bool isPrime(int n) {
  if (n < 2) return false;
  if (n % 2 == 0) return n == 2;
  if (n % 3 == 0) return n == 3;
  for (int i = 5; i * i <= n; i += 6)
    if (n % i == 0 || n % (i + 2) == 0)
      return false;
  return true;
}

std::stack<int> decompose(int n) {
  std::stack<int> temp;
  while (n % 2 == 0) {
    temp.push(2);
    n /= 2;
  }
  for (int i = 3; i * i <= n;)
    if (n % i == 0 && isPrime(i)) {
      temp.push(i);
      n /= i;
    } else i++;
  if (n > 1)
    temp.push(n);
  return temp;
}

Circle::Circle(int radius)
        : radius(radius) {}

Circle::Circle() : Circle(0) {}

int Circle::getRadius() const {
  return radius;
}

void Circle::setRadius(int newRadius) {
  if (newRadius < 0)
    throw std::invalid_argument("The radius must be non-negative integer.");
  radius = newRadius;
}

void Circle::add(const Circle &circle) {
  radius += circle.radius;
}

void Circle::addAll(const Circle *circles, int n) {
  for (int i = 0; i < n; i++)
    add(circles[i]);
}

int Circle::decompose(Circle *&circlesOutput) const {
  std::stack<int> integerDecompose = ::decompose(radius);
  circlesOutput = new Circle[integerDecompose.size()];
  int i = 0;
  while (!integerDecompose.empty()) {
    circlesOutput[i++].radius = integerDecompose.top();
    integerDecompose.pop();
  }
  return i;
}

std::ostream &operator<<(std::ostream &os, const Circle &circle) {
  os << "Circle(R: " << circle.radius << ')';
  return os;
}
