#include <iostream>
#include <string>

using std::cout, std::cin, std::endl, std::string;

void encrypt(string&);

int main(){
  string str;
  cin >> str;
  encrypt(str);
  cout << str;
  return 0;
}

void encrypt(string &str) {
  for (int i = 0;i + 1 < str.length();i += 2) {
    char t = str[i];
    str[i] = str[i + 1];
    str[i + 1] = t;
  }
  for (char &c : str)
    c = 219 - c; // NOLINT(cppcoreguidelines-narrowing-conversions)
}