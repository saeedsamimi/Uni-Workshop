#include "Rational.h"
#include <stdexcept>

Rational::Rational(int top, int down) {
  this->set(top, down);
}

void Rational::set(int top, int down) {
  if (down) {
    this->numerator = top;
    this->denominator = down;
    this->_simplify();
  }
  else throw std::invalid_argument("The denominator should be non-zero integer");
}

void Rational::printStandard(std::ostream &out) const {
  out << this->numerator << '/' << this->denominator;
}

void Rational::printNumeric(int precisions, std::ostream &out) const {
  out.precision(precisions);
  out << this->numerator / (double) this->denominator;
}

void Rational::_simplify() {
  int gcd = GCD(this->numerator, this->denominator);
  this->numerator /= gcd;
  this->denominator /= gcd;
}

Rational Rational::operator+(const Rational &a) const {
  return Rational(this->denominator * a.numerator + this->numerator * a.denominator,
                  this->denominator * a.denominator);
}

Rational Rational::operator-() const {
  return Rational(-this->numerator, this->denominator);
}

Rational Rational::operator-(const Rational &a) const {
  return this->operator+(-a);
}

Rational Rational::operator*(const Rational &a) const {
  return Rational(this->numerator * a.numerator,
                  this->denominator * a.denominator);
}

Rational Rational::operator/(const Rational &b) const {
  if (b.numerator)
    return Rational(this->numerator * b.denominator,
                    this->denominator * b.numerator);
  throw std::runtime_error("Division by zero exception!");
}

void Rational::operator+=(const Rational &a) {
  *this = *this + a;
}

void Rational::operator-=(const Rational &a) {
  *this = *this - a;
}

void Rational::operator*=(const Rational &a) {
  *this = *this * a;
}

void Rational::operator/=(const Rational &a) {
  *this = *this * a;
}

int GCD(int a, int b) {
  // Non-recursive form of GCD prevents from some errors such stackoverflow error
  // this function only can calculate the gcd of positive integers
  int c;
  while (b) {
    c = a % b;
    a = b;
    b = c;
  }
  return a;
}
