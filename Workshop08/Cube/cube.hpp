#ifndef CUBE_HPP
#define CUBE_HPP

#include <ostream>

float caster(int input, std::ostream &out);

class cube {
public:
  cube(float width, float height, float length);
  cube operator+(const cube &c);
  cube operator-(const cube &c);
  friend std::ostream &operator<<(std::ostream &, const cube &);

private:
  float width;
  float height;
  float area;
  float length;
  float volume;

  float area_util(float width, float height, float length);
  float volume_util(float width, float height, float length);
};

#endif // CUBE_HPP