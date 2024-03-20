// Workshop Q2
// Created by SaEeD on 3/9/2024.
// The Student class definition

#ifndef STUDENT_HEADER
#define STUDENT_HEADER

#include <string>

using std::string;

class Student {
public:
  // Constructors
  Student(string name, string major, int ID, char GPA, int passe);
  
  // Setter & Getter
  string getName();
  void setName(string &&newName);
  [[nodiscard]] int getID() const;
  void setID(int newID);
  [[nodiscard]] int getPassed() const;
  void setPassed(int newPassed);
  [[nodiscard]] char getGPA() const;
  void setGPA(char newGPA);
  [[nodiscard]] string getMajor() const;
  void setMajor(string &&newMajor);
  
  // Methods
  [[nodiscard]] int NumericAverage() const;
  [[nodiscard]] int PointsSum() const;
private:
  // Attributes
  string name;
  int ID;
  int passed;
  char GPA;
  string major;
};


#endif //STUDENT_HEADER
