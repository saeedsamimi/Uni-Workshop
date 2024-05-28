#include <algorithm>
#include "Employee.hpp"

float Employee::getArabic() const {
  return m_arabic;
}

void Employee::setArabic(float mArabic) {
  m_arabic = mArabic;
}

float Employee::getPersian() const {
  return m_persian;
}

void Employee::setPersian(float mPersian) {
  m_persian = mPersian;
}

float Employee::getEnglish() const {
  return m_english;
}

void Employee::setEnglish(float mEnglish) {
  m_english = mEnglish;
}

float Employee::getFrench() const {
  return m_french;
}

void Employee::setFrench(float mFrench) {
  m_french = mFrench;
}

int Employee::getExperience() const {
  return m_experience;
}

void Employee::setExperience(int mExperience) {
  m_experience = mExperience;
}

Employee::Employee(float arabic, float persian, float english, float french, int rexprience)
        : m_arabic(arabic), m_english(english), m_persian(persian), m_french(french), m_experience(rexprience) {}

std::string Employer::findBestEmployee(std::vector<Employee> &employees, Employment type) {
  std::sort(employees.begin(), employees.end(), [](const Employee &emp1, const Employee &emp2) {
      int les1 = emp1.lessons();
      int les2 = emp2.lessons();
      if (les1 == les2)
        return emp1.m_experience > emp2.m_experience;
      return les1 > les2;
  });
  return employees[0].m_fname + " " + employees[0].m_lname;
}

int Employee::lessons() const {
  int r = 0;
  if (this->m_arabic > .9)
    r++;
  if (this->m_persian > 0.9)
    r++;
  if (this->m_english > .9)
    r++;
  if (this->m_french > 0.9)
    r++;
  return r;
}

Employee &Employee::operator=(const Employee &r) {
  if (this != &r) {
    this->m_fname = r.m_fname;
    this->m_lname = r.m_lname;
    this->m_arabic = r.m_arabic;
    this->m_english = r.m_english;
    this->m_french = r.m_french;
    this->m_persian = r.m_persian;
    this->m_experience = r.m_experience;
  }
  return *this;
}

const std::string &Employee::getLName() const {
  return m_fname;
}

void Employee::setLName(const std::string &lname) {
  m_lname = lname;
}

const std::string &Employee::getFName() const {
  return m_lname;
}

void Employee::setFName(const std::string &fname) {
  m_fname = fname;
}

Employee::Employee(const Employee &emp) {
  *this = emp;
}

std::ostream &operator<<(std::ostream &out, const Employee &emp) {
  out << "Name: " << emp.m_fname << ' ' << emp.m_lname;
  out << "\nPoints: 1-Arabic: " << emp.m_arabic << "\t 2-Persian: " << emp.m_persian << "\t 3-English: " << emp.m_english << "\t 4-French: " << emp.m_french << '\n';
  return out;
}
