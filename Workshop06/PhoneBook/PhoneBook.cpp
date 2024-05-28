#include <algorithm>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() = default;

void PhoneBook::printSorted(ostream &out) {
  int i = 1;
  for (const Contact &contact: m_contacts_list)
    out << "\nContact #" << i++
        << "\tName: " << contact.m_name
        << " ;\n\tLastName: " << contact.m_lastname
        << " ;\n\tPhone: " << contact.m_phone;
}

void PhoneBook::addContact(const string &name, const string &lastName, const string &phone) {
  auto iter = m_contacts_list.begin();
  for (; iter != m_contacts_list.end() && iter->m_lastname < lastName; iter++);
  if (iter != m_contacts_list.end() && iter->m_name == name && iter->m_lastname == lastName)
    throw "The Contact with the same name is already exists!";
  Contact c;
  c.m_name = name;
  c.m_lastname = lastName;
  c.m_phone = phone;
  m_contacts_list.insert(iter, c);
}

string PhoneBook::search(const string &last_name) {
  auto res = std::find_if(m_contacts_list.begin(), m_contacts_list.end(), [last_name](const Contact &c) {
      return c.m_lastname == last_name;
  });
  if (res == m_contacts_list.end())
    throw "No item is found.";
  return res->m_phone;
}

size_t PhoneBook::count() {
  return m_contacts_list.size();
}

void PhoneBook::edit(const string &name, const string &lastName, const string &newPhoneNumber) {
  auto res = std::find_if(m_contacts_list.begin(), m_contacts_list.end(), [name, lastName](const Contact &c) {
      return c.m_lastname == lastName && c.m_name == name;
  });
  if (res == m_contacts_list.end())
    throw "No item is found!";
  res->m_phone = newPhoneNumber;
}


