#include "cube.hpp"

float caster(int input, std::ostream &out) {
  out << "Input type id: " << typeid(input).name() << std::endl;
  float temp = static_cast<float>(input);
  out << "Return type id: " << typeid(temp).name() << std::endl;
  return temp;
}

std::ostream &operator<<(std::ostream &out, const cube &c) {
  out << "width : " << c.width << '\t';
  out << "height : " << c.height << '\t';
  out << "length : " << c.length << "\t\n";
  out << "area : " << c.area << '\t';
  out << "volume : " << c.volume << '\n';
  return out;
}

cube::cube(float width, float height, float length)
    : width(width), height(height), length(length),
      area(area_util(width, height, length)),
      volume(volume_util(width, height, length)) {}

cube cube::operator+(const cube &c) {
  return cube{width + c.width, height + c.height, length + c.length};
}

cube cube::operator-(const cube &c) {
  return cube{width - c.width, height - c.height, length - c.length};
}

float cube::volume_util(float width, float height, float length) {
  return 2 * (width * height + width * length + length * height);
}

float cube::area_util(float width, float height, float length) {
  return width * height * length;
}