#include "bankaccount.hpp"
#include <fstream>
#include <istream>

BankAccount::BankAccount(const std::string &&user_name,
                         unsigned long long account_no,
                         unsigned int balance) noexcept
    : m_name(user_name), m_account_no(account_no), m_balance(balance),
      m_transaction_history() {}

void BankAccount::deposit(unsigned int value) noexcept {
  m_balance += value;
  m_transaction_history.push_back(value);
}

void BankAccount::withdraw(unsigned int value) {
  if (m_balance >= value) {
    m_balance -= value;
    m_transaction_history.push_back(-value);
  } else
    throw NotEnoughBalanaceException();
}

unsigned long long BankAccount::getAccountNumber() const {
  return m_account_no;
}

std::string BankAccount::getOwner() const { return m_name; }

void BankAccount::operator-=(unsigned int amount) { withdraw(amount); }

void BankAccount::operator+=(unsigned int amount) noexcept { deposit(amount); }

void BankAccount::transferFunds(BankAccount &from, BankAccount &to,
                                unsigned long long amount) {
  from.withdraw(amount);
  to.deposit(amount);
}

bool BankAccount::save(const BankAccount &b, const char *fileName) {
  std::ofstream out(fileName);
  if (out.is_open()) {
    out << b;
    out.close();
    return true;
  } else
    return false;
}

BankAccount BankAccount::load(const char *fileName) {
  std::ifstream in(fileName);
  if (in.is_open()) {
    // read owner
    in.ignore(7);
    BankAccount acc;
    in >> acc.m_name;
    in.ignore(12);
    in >> acc.m_account_no;
    in.ignore(16);
    in >> acc.m_balance;
    std::string s;
    getline(in, s);
    if (s.back() != '!') {
      while (in.eof()) {
        in >> s;
        int amount;
        in >> amount;
        acc.m_transaction_history.push_back(s[0] == 'w' ? -amount : amount);
      }
    }
    in.close();
    return acc;
  } else
    throw FileCannotOpenException();
}

BankAccount::BankAccount()
    : m_name(), m_balance(0), m_transaction_history(), m_account_no(0) {}

void BankAccount::printBalance(std::ostream &out) const {
  out << "Balance: " << m_balance << std::endl;
}

const char *NotEnoughBalanaceException::what() const noexcept {
  return "The balance is not enough!";
}

const char *FileCannotOpenException::what() const noexcept {
  return "The file cannot be opened!";
}

std::ostream &operator<<(std::ostream &out, const BankAccount &b) {
  out << "Owner: " << b.m_name << std::endl;
  out << "CardNumber: " << b.m_account_no << std::endl;
  out << "CurrentBalance: " << b.m_balance << std::endl;
  if (b.m_transaction_history.empty())
    out << "No transaction found!";
  else {
    out << "Last 10 History: ";
    for (auto riter = b.m_transaction_history.rbegin();
         riter != b.m_transaction_history.rend(); riter++)
      out << '\n'
          << (*riter >= 0 ? "deposit" : "withdraw") << ": " << abs(*riter);
  }
  return out << std::endl;
}
