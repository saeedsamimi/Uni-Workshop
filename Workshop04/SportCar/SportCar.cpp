#include "SportCar.h"

Engine::Engine(int volume, int power, int cylinders_count, const std::string &&fuel_type)
        : volume(volume),
          power(power),
          cylindersCount(cylinders_count),
          fuelType(fuel_type) {}

int Engine::getVolume() const {
  return volume;
}

void Engine::setVolume(int _volume) {
  volume = _volume;
}

int Engine::getPower() const {
  return power;
}

void Engine::setPower(int _power) {
  power = _power;
}

int Engine::getCylindersCount() const {
  return cylindersCount;
}

void Engine::setCylindersCount(int _cylindersCount) {
  cylindersCount = _cylindersCount;
}

const std::string &Engine::getFuelType() const {
  return fuelType;
}

void Engine::setFuelType(const std::string &_fuelType) {
  fuelType = _fuelType;
}

Window::Window(int width, int height, Window::GlassType type)
        : width(width),
          height(height),
          type(type) {}

int Window::getWidth() const {
  return width;
}

void Window::setWidth(int _width) {
  width = _width;
}

int Window::getHeight() const {
  return height;
}

void Window::setHeight(int _height) {
  height = _height;
}

Window::GlassType Window::getType() const {
  return type;
}

void Window::setType(Window::GlassType _type) {
  type = _type;
}

Wheel::Wheel(int diameter, double pressure)
        : diameter(diameter),
          tire_pressure(pressure) {}

Door::Door(Door::DoorType type)
        : type(type) {}

Door::DoorType Door::getType() const {
  return type;
}

void Door::setType(Door::DoorType type) {
  Door::type = type;
}

SportCar::SportCar() = default;

void Wheel::decreasePressure(double value) {
  tire_pressure -= value;
}

void Wheel::increasePressure(double value) {
  tire_pressure += value;
}

int Wheel::getDiameter() const {
  return diameter;
}

void Wheel::setDiameter(int _diameter) {
  diameter = _diameter;
}

double Wheel::getTirePressure() const {
  return tire_pressure;
}

void Wheel::setTirePressure(double tirePressure) {
  tire_pressure = tirePressure;
}


void SportCar::setEngine(Engine *engine) {
  m_engine = engine;
}

Engine *SportCar::getEngine() {
  return m_engine;
}

void SportCar::setWins(Window wins[2]) {
  memcpy(m_wins,wins,sizeof(Window) * 2);
}

Window *SportCar::getWin(int index) {
  return m_wins + index;
}

void SportCar::setWin(int index, Window *win) {
  m_wins[index] = *win;
}

void SportCar::setWheels(Wheel wheels[4]) {
  memcpy(m_wheels,wheels,sizeof(Wheel) * 4);
}

Wheel *SportCar::getWheel(int index) {
  return m_wheels+index;
}

void SportCar::setWheel(int index, Wheel *wheel) {
  m_wheels[index] = *wheel;
}

void SportCar::setDoors(Door doors[2]) {
  memcpy(m_doors,doors,sizeof(Door) * 2);
}

Door *SportCar::getDoor(int index) {
  return m_doors+index;
}

void SportCar::setDoor(int index, Door *door) {
  m_doors[index] = *door;
}
