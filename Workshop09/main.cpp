#include <iostream>
#include <overnightpackage.h>
#include <twodaypackage.h>

using namespace std;

ostream &operator<<(std::ostream &out, const Package &pkg) {
  return out << "Package: \nFrom: " <<
      pkg.getFirstName() << ' ' << pkg.getLastName() << "\n\t\tby address: " << pkg.getAddress() <<
      ' ' << pkg.getCity() << "\n to post: " << pkg.getReceiverPost() << "\n and by cost: " << pkg.calculateCost()
      << endl;
}

int main() {
  TwoDayPackage pkg("saeed", "samimi",
                    "iran/khorasan/mashhad/sakhtemoon",
                    "mashhad", "USS", "3434314", "4656456",
                    1200, 120.5);
  OverNightPackage pkg2("mahdi", "ahmadvand",
                        "iran/tehran/tehran",
                        "tehran", "Niavaran", "1200000", "112222",
                        10200, 100.9);
  cout << pkg << endl << pkg2;
  return 0;
}
