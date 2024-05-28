#ifndef APP_BINARYNUMBER_HPP
#define APP_BINARYNUMBER_HPP
#include <string>
#include <ostream>
#include <istream>

class BinaryNumber {
public:
  BinaryNumber() = default;
  BinaryNumber(int d);
  BinaryNumber(const std::string &&num);
  
  void setNumber(const std::string &&num);
  [[nodiscard]] std::string getNumber() const;
  std::string extend();
  [[nodiscard]] int toDecimal() const;
  BinaryNumber operator +(const BinaryNumber &num) const;
  BinaryNumber operator *(const BinaryNumber &num) const;
  BinaryNumber operator -(const BinaryNumber &num) const;
  BinaryNumber operator -() const;
  BinaryNumber operator >>(unsigned int a) const;
  BinaryNumber operator <<(unsigned int a) const;
  friend std::ostream &operator<<(std::ostream &os, const BinaryNumber &number);
  friend std::istream &operator>>(std::istream &is, BinaryNumber &number);
private:
  int number[32] = {0};
  
  std::string complement() const;
};


#endif //APP_BINARYNUMBER_HPP
