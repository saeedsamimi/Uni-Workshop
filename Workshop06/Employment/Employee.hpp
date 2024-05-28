#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <string>
#include <vector>
#include <ostream>

enum Employment {
  service,
  reception,
  facility,
  administration
};

class Employer;

class Employee;

class Employer {
private:
  int empNum;
public:
  Employer() = default;
  std::string findBestEmployee(std::vector<Employee> &employees, Employment type);
};

class Employee {
public:
  [[nodiscard]] float getArabic() const;
  void setArabic(float mArabic);
  [[nodiscard]] float getPersian() const;
  void setPersian(float mPersian);
  [[nodiscard]] float getEnglish() const;
  void setEnglish(float mEnglish);
  [[nodiscard]] float getFrench() const;
  void setFrench(float mFrench);
  [[nodiscard]] int getExperience() const;
  void setExperience(int mExperience);
  void setFName(const std::string &fname);
  [[nodiscard]] const std::string &getFName() const;
  void setLName(const std::string &lname);
  [[nodiscard]] const std::string &getLName( ) const;
private:
  float m_arabic, m_persian, m_english, m_french;
  std::string m_fname,m_lname;
  int m_experience;
public:
  explicit Employee(float arabic = 0, float persian = 0, float english = 0, float french = 0, int exprience = 0);
  Employee(const Employee &);
  Employee &operator=(const Employee &r);
  int lessons() const;
  friend std::string Employer::findBestEmployee(std::vector<Employee> &, Employment);
  friend std::ostream &operator<<(std::ostream &out,const Employee &emp);
};


#endif //EMPLOYEE_HPP
