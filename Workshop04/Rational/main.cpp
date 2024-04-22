#include "Rational.h"

void printUtil(char name,const Rational& a){
  std::cout << name << ':';
  a.printStandard();
  std::cout << " = \t";
  a.printNumeric(3);
  std::cout << std::endl;
}

int main() {
  Rational a(12,34);
  Rational b(25,1250);
  Rational c(129,21);
  
  //** begin testing print operations
  printUtil('a',a);
  printUtil('b',b);
  printUtil('c',c);
  //** end testing print operations
  
  //** begin test invalid argument and division by zero operations
  try{
    Rational d(1,0);
  }catch(std::exception &exception){
    std::cout << "The error occurred: " << exception.what() << std::endl;
  }
  try{
    Rational m;
    Rational n = a / m;
  }catch (std::exception &exception){
    std::cout << "the error occurred: " << exception.what() << std::endl;
  }
  //** end test invalid argument and .etc
  
  //** begin test operations
  Rational d = a + b;
  Rational e = a - b;
  Rational f = b * a;
  Rational t = b / a;
  Rational l = a * b * c - a - b + c;
  std::cout << "\n a + b : \n";
  d.printStandard();
  std::cout << "\n a - b : \n";
  e.printStandard();
  std::cout << "\n a * b : \n";
  f.printStandard();
  std::cout << "\n b / a : \n";
  t.printStandard();
  std::cout << "\n a * b * c - a - b + c : \n";
  l.printStandard();
  //** end test operations
  return 0;
}
