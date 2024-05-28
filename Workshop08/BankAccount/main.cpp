#include "bankaccount.hpp"
#include <iostream>

using namespace std;

int main() {
  BankAccount account1("saeed", 6362141809028849, 375000);
  BankAccount account2("mahdi", 6362090090290119, 12000);
  account1.deposit(12000);
  cout << account1 << std::endl;
  cout << account2 << std::endl;
  account2.printBalance(cout);
  try {
    account2.withdraw(12001);
  } catch (NotEnoughBalanaceException &e) {
    cout << "Err: " << e.what() << endl;
  }
  BankAccount::transferFunds(account1, account2, 100000);
  BankAccount::transferFunds(account2, account1, 1000);
  try {
    BankAccount::transferFunds(account2, account1, 10000000);
  } catch (NotEnoughBalanaceException &e) {
    cout << e.what() << endl;
  }
  cout << "Save Status: " << boolalpha << BankAccount::save(account1, "out.txt")
       << endl;
}