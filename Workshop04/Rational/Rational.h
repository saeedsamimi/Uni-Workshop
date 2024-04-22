#ifndef FRACTION_RATIONAL_H
#define FRACTION_RATIONAL_H

#include <ostream>
#include <iostream>

class Rational {
public:
  explicit Rational(int top = 0, int down = 1);
  
  void set(int top, int down);
  
  void printStandard(std::ostream &out = std::cout) const;
  void printNumeric(int precisions = 2,std::ostream &out = std::cout) const;
  
  Rational operator-() const;
  Rational operator+(const Rational &a) const;
  Rational operator-(const Rational &a) const;
  Rational operator*(const Rational &a) const;
  Rational operator/(const Rational &b) const;
  void operator+=(const Rational &a);
  void operator-=(const Rational &a);
  void operator*=(const Rational &a);
  void operator/=(const Rational &a);
private:
  int numerator, denominator;
  
  void _simplify();
};

int GCD(int a, int b);

#endif //FRACTION_RATIONAL_H
