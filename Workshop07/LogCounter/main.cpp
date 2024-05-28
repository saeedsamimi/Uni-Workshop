#include "Admin.hpp"

using std::cout, std::endl;

int main() {
  // test #1 with empty constructor
  Admin admin1;
  cout << "Admin1: name" << admin1.getName() << " lastname: " << admin1.getLastName() << endl;
  admin1.setName("saeed").printLogName();
  admin1.setLastName("samimi").printLogLastName();
  // test #2 with defined(described) admin identity
  Admin admin2("mahdi", "rezvani");
  cout << "Admin2: name" << admin2.getName() << " lastname: " << admin2.getLastName() << endl;
  admin2.setName("Mahdi").printLogName();
  admin2.setName("morteza").printLogName();
  admin2.setName("Javad").printLogName();
  admin2.setName("Mohammad").printLogLastName();
  // test #3 with defined(described) admin and many identities
  Admin admin3;
  cout << "Admin3: name" << admin2.getName() << " lastname: " << admin2.getLastName() << endl;
  for (auto &str: {"hello", "how", "are", "you"})
    admin3.setName(str).printLogName();
  for (auto &str: {"Hi", "Iam", "Fine", "Thank you"})
    admin3.setLastName(str).printLogLastName();
  return 0;
}