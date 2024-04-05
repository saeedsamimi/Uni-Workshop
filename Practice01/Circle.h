#ifndef MAIN_CIRCLE_H
#define MAIN_CIRCLE_H

#include <stack>
#include <ostream>

// util function for permeability checking
bool isPrime(int);

[[nodiscard]] std::stack<int> decompose(int);

class Circle {
public:
  Circle();
  explicit Circle(int);
  
  [[nodiscard]] int getRadius() const;
  void setRadius(int);
  
  void add(const Circle &);
  void addAll(const Circle [], int);
  
  // returns an array of prime decomposers
  [[nodiscard]] int decompose(Circle *&) const;
  
  friend std::ostream &operator<<(std::ostream &os, const Circle &circle);
private:
  int radius;
};


#endif //MAIN_CIRCLE_H
