#ifndef BANKACCOUNT_HPP
#define BANKACCOUNT_HPP

#include <exception>
#include <ostream>
#include <string>
#include <vector>

class NotEnoughBalanaceException : public std::exception {
public:
  const char *what() const _GLIBCXX_TXN_SAFE_DYN noexcept override;
  ~NotEnoughBalanaceException() {}
};

class FileCannotOpenException : public std::exception {
public:
  const char *what() const _GLIBCXX_TXN_SAFE_DYN noexcept override;
  ~FileCannotOpenException() {}
};

class BankAccount {
public:
  BankAccount(const std::string &&user_name, unsigned long long account_no,
              unsigned int balance) noexcept;

  void deposit(unsigned int value) noexcept;
  void withdraw(unsigned int value);
  void printBalance(std::ostream &out) const;
  unsigned long long getAccountNumber() const;
  std::string getOwner() const;
  void operator+=(unsigned int amount) noexcept;
  void operator-=(unsigned int amount);
  friend std::ostream &operator<<(std::ostream &out, const BankAccount &b);
  static void transferFunds(BankAccount &from, BankAccount &to,
                            unsigned long long amount);
  static bool save(const BankAccount &b, const char *fileName);
  static BankAccount load(const char *fileName);

private:
  std::string m_name;
  unsigned long long m_account_no;
  unsigned int m_balance;
  std::vector<int> m_transaction_history;
  BankAccount();
};

#endif // BANKACCOUNT_HPP