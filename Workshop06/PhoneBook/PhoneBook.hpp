#ifndef PHONEBOOK_CONTACTS_HPP
#define PHONEBOOK_CONTACTS_HPP

#include <string>

using std::string;

class Contact {
private:
  string m_name, m_lastname, m_phone;
public:
  friend class PhoneBook;
};

#endif //PHONEBOOK_CONTACTS_HPP

#ifndef PHONEBOOK_PHONEBOOK_HPP
#define PHONEBOOK_PHONEBOOK_HPP

#include <vector>
#include <ostream>

using std::ostream;

class PhoneBook {
private:
  using contacts_list = std::vector<Contact>;
  contacts_list m_contacts_list;
public:
  PhoneBook();
  void addContact(const string &name, const string &lastName, const string &phone);
  void printSorted(ostream &out);
  string search(const string &last_name);
  size_t count();
  void edit(const string &name,const string &lastName,const string& newPhoneNumber);
};


#endif //PHONEBOOK_PHONEBOOK_HPP
