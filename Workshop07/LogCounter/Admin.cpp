#include "Admin.hpp"

Admin::Admin(const string &&name, const string &&lastname) : m_name(name), m_last_name(lastname) {}

const string &Admin::getName() const {
  return m_name;
}

const string &Admin::getLastName() const {
  return m_last_name;
}

void Admin::printLogName(std::ostream &out) const {
  out << "field name has been changed " << m_counter_name << " times." << std::endl;
}

void Admin::printLogLastName(std::ostream &out) const {
  out << "field lastname has been changed " << m_counter_last_name << " times." << std::endl;
}

const Admin &Admin::setName(const string &&newName) {
  m_name = newName;
  m_counter_name++;
  return *this;
}

const Admin &Admin::setLastName(const string &&newLastName) {
  m_last_name = newLastName;
  m_counter_last_name++;
  return *this;
}

Admin::Admin() = default;
