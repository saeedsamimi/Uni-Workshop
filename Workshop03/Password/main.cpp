// Workshop Q2
// Created by SaEeD on 3/9/2024.
// The main file definition
#include <iostream>
#include "password.h"

using namespace std;

int main() {
  Password pass1, pass2;
  pass1.setPassword("HelloHowAreYou232323Today1392");
  pass2.setPassword("THis is Wrong password because have space and dont have numbers");
  cout << "Password 1 is: " << pass1.getPassword() << endl;
  cout << "Pass 1 validation status is : " << boolalpha << pass1.checkPass() << '\n' << endl;
  cout << "Password 2 is: " << pass2.getPassword() << endl;
  cout << "Pass 2 validation status is : " << boolalpha << pass2.checkPass() << '\n' << endl;
  return 0;
}
