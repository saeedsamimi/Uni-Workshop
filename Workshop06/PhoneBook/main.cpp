#include <iostream>
#include "PhoneBook.hpp"

using namespace std;

int main() {
  PhoneBook phoneBook;
  try {
    phoneBook.addContact("saeed", "samimi", "+9899289012");
    phoneBook.addContact("mahdi", "razavi", "+9723122332");
    phoneBook.addContact("mahdi", "razavi", "+2434343443");
  } catch (const char *errMsg) {
    cout << "Error occurred while trying to add contact: " << errMsg << endl;
  }
  phoneBook.addContact("javad","rezvani","+5632323323");
  phoneBook.addContact("reza","ahmadabadi","+10454545094");
  cout << "Display current contacts: ";
  phoneBook.printSorted(cout);
  cout << "Searching the contact \'samimi\': " << phoneBook.search("samimi") << endl;
  try {
    cout << "Searching the contact \'yer\': " << phoneBook.search("yer") << endl;
  } catch (const char *errMsg) {
    cout << "Find contact error occurred: " << errMsg << endl;
  }
  cout << "Display current contacts count: " << phoneBook.count() << endl;
  cout << R"(Try to edit the contact 'samimi' and contact 'mahdavi':)";
  try{
    phoneBook.edit("saeed","samimi","+989331353434");
    cout << "successfully!" << endl;
  }catch (const char *errMsg){
    cout << "Error while editing contact: "<<errMsg << endl;
  }
  try{
    phoneBook.edit("vahid","mahdavi","+9893317775634");
    cout << "successfully!" << endl;
  }catch (const char *errMsg){
    cout << "Error while editing contact: "<<errMsg << endl;
  }
  return 0;
}