// Workshop Q3
// Created by SaEeD on 3/9/2024.
// The main file definition
#include <iostream>
#include "Student.h"

using namespace std;

int main() {
  Student student1("saeed samimi", "Computer Engineering", 30393029, 'A', 17);
  Student student2("Mahdi Asghari","Lawyer",349833535,'B',100);
  Student student3("ali rezvani" , "Teacher",293844,'E',2309293);
  cout << "Student1: " << student1.getName() << endl;
  cout << "Numeric average: " << student1.NumericAverage() << endl;
  cout << "GPA: " << student1.getGPA() << endl;
  cout << "Sum of points:" << student1.PointsSum() << endl;
  /////////////////////////////////////////////////////////
  cout << "Student2: " << student2.getName() << endl;
  cout << "Numeric average: " << student2.NumericAverage() << endl;
  cout << "GPA: " << student2.getGPA() << endl;
  cout << "Sum of points:" << student2.PointsSum() << endl;
  /////////////////////////////////////////////////////////
  cout << "Student3: " << student3.getName() << endl;
  cout << "Numeric average: " << student3.NumericAverage() << endl;
  cout << "GPA: " << student3.getGPA() << endl;
  cout << "Sum of points:" << student3.PointsSum() << endl;
  return 0;
}