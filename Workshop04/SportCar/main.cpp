#include <iostream>
#include "SportCar.h"

using namespace std;

int main() {
  Engine engine(400, 300, 8, "Gasoline");
  Wheel wheels[4]{
          {30, 340.5},
          {30, 120.5},
          {35, 200.5},
          {35, 350.4}
  };
  Window wins[2]{
          {100, 200, Window::Transparent},
          {100, 200, Window::Opaque},
  };
  Door doors[2]{
          {Door::OpenUp},
          {Door::OpenUp}
  };
  SportCar car;
  car.setEngine(&engine);
  car.setDoors(doors);
  car.setWheels(wheels);
  car.setWins(wins);
  // print all identifications of car
  cout << "Car: \n";
  cout << "\tEngine: \n";
  cout << "\t\tVolume: " << car.getEngine()->getVolume() << endl;
  cout << "\t\tPower: " << car.getEngine()->getPower() << endl;
  cout << "\t\tCylinders Count: " << car.getEngine()->getCylindersCount() << endl;
  cout << "\t\tFuel Type: " << car.getEngine()->getFuelType() << endl;
  cout << "\tDoors: (1: openUp, 0: normalMode)\n";
  for (int i = 0; i < 2; i++) {
    cout << "\t\tDoor #" << i + 1 << ":\n";
    cout << "\t\t\tDoorType: " << car.getDoor(i)->getType() << endl;
  }
  cout << "\tWheels: \n";
  for (int i = 0; i < 4; i++) {
    cout << "\t\tWheel #" << i + 1 << ":\n";
    cout << "\t\t\tDiameter: " << car.getWheel(i)->getDiameter() << endl;
    cout << "\t\t\tPressure: " << car.getWheel(i)->getTirePressure() << endl;
  }
  cout << "\tWindows: (0: Transparent, 1: Opaque)\n";
  for (int i = 0; i < 2; i++) {
    cout << "\t\tWindow #" << i + 1 << ":\n";
    cout << "\t\t\tSize: {" << car.getWin(i)->getWidth() << ',' << car.getWin(i)->getHeight() << '}' << endl;
    cout << "\t\t\tType: " << car.getWin(i)->getType() << endl;
  }
  return 0;
}
