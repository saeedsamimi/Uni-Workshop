// Workshop Q2
// Created by SaEed on 3/9/2024.
// the class declaration

#include "password.h"
#include <stdexcept>

using std::invalid_argument;

Password::Password() : Pass(string()) {}

string Password::getPassword() {
  return Pass;
}

void Password::setPassword(string newPass) {
  Pass = std::move(newPass);
}

bool Password::checkPass() {
  bool hasDigit = false, hasAlphabet = false;
  for (const char c: Pass) {
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
      hasAlphabet = true;
    else if (c >= '0' && c <= '9')
      hasDigit = true;
    else
      return false;
  }
  return hasDigit && hasAlphabet;
}