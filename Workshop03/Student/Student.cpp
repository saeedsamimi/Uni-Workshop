// Workshop Q2
// Created by SaEeD on 3/9/2024.
// The Student class declaration

#include "Student.h"

Student::Student(string name,string major,int ID,char GPA,int passe) {
  setName(std::move(name));
  setGPA(GPA);
  setID(ID);
  setMajor(std::move(major));
  setPassed(passe);
}

void Student::setPassed(int newPassed) {
  passed = newPassed;
}

void Student::setMajor(string &&newMajor) {
  major = newMajor;
}

void Student::setID(int newID) {
  ID = newID;
}

void Student::setGPA(char newGPA) {
  GPA = newGPA;
}

void Student::setName(std::string &&newName) {
  name = newName;
}

char Student::getGPA() const {
  return GPA;
}

int Student::getID() const {
  return ID;
}

string Student::getMajor() const {
  return major;
}

int Student::getPassed() const {
  return passed;
}

string Student::getName() {
  return name;
}

int Student::NumericAverage() const {
  switch (GPA) {
    case 'A':
      return 20;
    case 'B':
      return 16;
    case 'C':
      return 12;
    case 'D':
      return 8;
    case 'E':
      return 0;
    default:
      return -1; // for invalid data
  }
}

int Student::PointsSum() const {
  return NumericAverage() * passed;
}