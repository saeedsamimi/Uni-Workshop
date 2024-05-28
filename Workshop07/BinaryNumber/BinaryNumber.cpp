#include "BinaryNumber.hpp"
#include <stdexcept>

BinaryNumber::BinaryNumber(const std::string &&num) {
  setNumber(std::move(num));
}

void BinaryNumber::setNumber(const std::string &&num) {
  for (char c: num)
    if (c != '0' && c != '1')
      throw std::invalid_argument("The num must be in binary representation!");
  int j = 31;
  for (auto i = num.rbegin(); i != num.rend(); i++)
    number[j--] = *i - '0';
}

std::string BinaryNumber::getNumber() const {
  std::string temp;
  temp.resize(32);
  for (int i = 0; i < 32; i++)
    temp[i] = number[i] ? '1' : '0';
  return temp;
}

std::string BinaryNumber::extend() {
  std::string temp;
  temp.resize(32);
  int i;
  bool first = false;
  for (i = 0; i < 32; i++) {
    temp[i] = number[i] + '0';
    if (!number[i] && !first)
      temp[i] = '1';
    else
      first = true;
  }
  return temp;
}

int BinaryNumber::toDecimal() const {
  int temp = 0;
  bool isNegative = number[0];
  std::string number(isNegative ? complement() : getNumber());
  int i = 31;
  for (char c: number) {
    if (c == '1')
      temp += 1 << i;
    i--;
  }
  if (isNegative)
    return -(temp + 1);
  return temp;
}

std::string BinaryNumber::complement() const {
  std::string temp;
  temp.resize(32);
  for (int i = 0; i < 32; i++)
    temp[i] = number[i] ? '0' : '1';
  return temp;
}

std::ostream &operator<<(std::ostream &os, const BinaryNumber &number) {
  for (int i: number.number)
    os << i;
  return os;
}

std::istream &operator>>(std::istream &is, BinaryNumber &number) {
  std::string temp;
  char t;
  for (int i = 0; i < 32; i++) {
    is.read(&t, 1);
    if (t == '0' || t == '1')
      temp.push_back(t);
    else
      break;
  }
  number.setNumber(std::move(temp));
  return is;
}

BinaryNumber BinaryNumber::operator>>(unsigned int a) const {
  BinaryNumber temp(*this);
  for (int i = 32 - a; i >= 0; i--) {
    temp.number[i + a] = temp.number[i];
    temp.number[i] = 0;
  }
  return temp;
}

BinaryNumber BinaryNumber::operator<<(unsigned int a) const {
  BinaryNumber temp(*this);
  for (int i = a; i < 32; i--) {
    temp.number[i - a] = temp.number[i];
    temp.number[i] = 0;
  }
  return temp;
}

BinaryNumber BinaryNumber::operator+(const BinaryNumber &num) const {
  return toDecimal() + num.toDecimal();
}

BinaryNumber::BinaryNumber(int d) {
  bool isNegative = d < 0;
  if (isNegative)
    d = -d - 1;
  unsigned int i = 31;
  while (d) {
    number[i--] = d % 2;
    d /= 2;
  }
  if (isNegative)
    for (int &j: number)
      j = !j;
}

BinaryNumber BinaryNumber::operator*(const BinaryNumber &num) const {
  return toDecimal() * num.toDecimal(); // uses the reassign algorithm
}

BinaryNumber BinaryNumber::operator-(const BinaryNumber &num) const {
  return toDecimal() - num.toDecimal(); // uses the reassign algorithm
}

BinaryNumber BinaryNumber::operator-() const {
  return -toDecimal(); // uses the reassign algorithm
}

