// Workshop03 Q1
// Created by SaEeD on 3/8/2024.
// CIRCLE <Header file>

#ifndef CIRCLE_HEADER
#define CIRCLE_HEADER


class Circle {
public:
  // Constructors
  Circle();
  explicit Circle(double);
  
  // Methods
  [[nodiscard("the Perimeter should be used")]]
  double Perimeter() const;
  [[nodiscard("the Area should be used")]]
  double Area() const;
  
  // Static Util Functions
  static bool compare(Circle &cir1,Circle &cir2);
private:
  // Private Attributes
  double radius;
};


#endif //CIRCLE_HEADER
