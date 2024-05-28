#ifndef APP_ADMIN_HPP
#define APP_ADMIN_HPP

#include <string>
#include <iostream>
#include "Log.hpp"

using std::string;

class Admin {
private:
  string m_name, m_last_name;
  
  Log m_counter_name, m_counter_last_name;

public:
  Admin();
  Admin(const string &&,const string &&);
  [[nodiscard]] const string &getName() const;
  [[nodiscard]] const string &getLastName() const;
  const Admin& setName(const string&&);
  const Admin& setLastName(const string&&);
  void printLogName(std::ostream & = std::cout) const;
  void printLogLastName(std::ostream & = std::cout) const;
};


#endif //APP_ADMIN_HPP
