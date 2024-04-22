#include <string>

#ifndef ENGINE_H
#define ENGINE_H

struct Engine {
public:
  Engine(int volume, int power, int cylinders_count, const std::string &&fuel_type);
  [[nodiscard]] int getVolume() const;
  void setVolume(int volume);
  [[nodiscard]] int getPower() const;
  void setPower(int power);
  [[nodiscard]] int getCylindersCount() const;
  void setCylindersCount(int cylindersCount);
  [[nodiscard]] const std::string &getFuelType() const;
  void setFuelType(const std::string &fuelType);
  
  friend class SportCar;

private:
  int volume;
  int power;
  int cylindersCount;
  std::string fuelType;
  Engine() = default;
};

#endif // ENGINE_H

#ifndef CLASS_WINDOW_H
#define CLASS_WINDOW_H

struct Window {
public:
  enum GlassType {
    Transparent,
    Opaque
  };
  Window(int width, int height, GlassType type);
  
  [[nodiscard]] int getWidth() const;
  void setWidth(int width);
  [[nodiscard]] int getHeight() const;
  void setHeight(int height);
  [[nodiscard]] GlassType getType() const;
  void setType(GlassType type);
  
  friend class SportCar;

private:
  int width;
  int height;
  GlassType type;
  Window() = default;
};

#endif // CLASS_WINDOW_H

#ifndef WHEEL_H
#define WHEEL_H

struct Wheel {
public:
  Wheel(int diameter, double pressure);
  
  friend class SportCar;
  
  void decreasePressure(double value);
  void increasePressure(double value);
  [[nodiscard]] int getDiameter() const;
  void setDiameter(int diameter);
  [[nodiscard]] double getTirePressure() const;
  void setTirePressure(double tirePressure);
private:
  int diameter;
  double tire_pressure;
  Wheel() = default;
};

#endif // WHEEL_H

#ifndef DOOR_H
#define DOOR_H

struct Door {
public:
  enum DoorType {
    Normal,
    OpenUp
  };
  Door(DoorType type);
  [[nodiscard]] DoorType getType() const;
  void setType(DoorType type);
  
  friend class SportCar;

private:
  DoorType type;
  Door() = default;
};

#endif // DOOR_H

#ifndef SPORT_CAR_H
#define SPORT_CAR_H

class SportCar {
public:
  SportCar();
  
  void setEngine(Engine *engine);
  Engine *getEngine();
  
  void setWins(Window wins[2]);
  Window *getWin(int index);
  void setWin(int index, Window *win);
  
  void setWheels(Wheel wheels[2]);
  Wheel *getWheel(int index);
  void setWheel(int index, Wheel *wheel);
  
  void setDoors(Door doors[2]);
  Door *getDoor(int index);
  void setDoor(int index, Door *door);
private:
  Engine *m_engine = nullptr;
  Window m_wins[2];
  Wheel m_wheels[2];
  Door m_doors[2];
};


#endif //SPORT_CAR_H
