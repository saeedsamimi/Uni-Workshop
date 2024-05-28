#include <iostream>
#include <Employee.hpp>

using namespace std;

int main() {
  Employee emp1(.5, .4, .6, .5, 100);
  emp1.setFName("Saeed");
  emp1.setLName("Samimi");
  Employee emp2(.3, .2, .9, .1, 50);
  emp2.setFName("Mohammad");
  emp2.setLName("Aliaghaii");
  Employee emp3(.9, .9, .3, .2, 70);
  emp3.setFName("Mehran");
  emp3.setLName("Mousavi");
  Employee emp4(.95, .95, .95, 0, 100);
  emp4.setFName("ALi asghar");
  emp4.setLName("Molavi");
  Employee emp5(1.0, .95, .95, .95, 0);
  emp5.setFName("Sam");
  emp5.setLName("Hamedani");
  Employer employer{};
  auto list = vector<Employee>{emp1, emp2, emp3, emp4, emp5};
  cout << "Employees is: \n";
  for(auto item : list){
    cout << "Employee: \n\t";
    cout << item;
  }
  cout << employer.findBestEmployee(list, Employment::reception);
  return 0;
}