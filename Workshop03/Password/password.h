// Workshop03 Q2
// Created by SaEeD on 3/9/2024.
// the class declaration

#ifndef PASSWORD_HEADER
#define PASSWORD_HEADER

#include <string>

using std::string;

class Password {
public:
  // Constructor
  Password();
  
  // Getter and setter
  string getPassword();
  void setPassword(string newPass);
  
  // Methods implementation
  bool checkPass();
private:
  // Private attributes
  string Pass;
};


#endif //PASSWORD_HEADER
