#include <iostream>
#include "BinaryNumber.hpp"

using namespace std;

int main() {
  BinaryNumber num1("10101");
  cout << "num1 : " << num1 << ", and by value : " << num1.toDecimal() << endl;
  BinaryNumber num2("10101010");
  cout << "num2 : " << num2 << ", and by value : " << num2.toDecimal() << endl;
  cout << "num1 + num2 : " << num2 + num1 << endl;
  cout << "num1 * num2 : " << num2 * num1 << endl;
  cout << "num1 - num2 : " << num2 - num1 << endl;
  BinaryNumber s(-100000);
  cout << "negative number: " << s << "  , positive number: " << -s << endl;
  cout << "please enter a binary number to test the binary istream operator: ";
  BinaryNumber t;
  cin >> t;
  cout << "The number you wrote: " << t << ", With decimal representation: " << t.toDecimal();
  return 0;
}