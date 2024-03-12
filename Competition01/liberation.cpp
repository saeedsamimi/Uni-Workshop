#include <iostream>

using namespace std;

bool check(int lock[2][5]) {
  int temp = 0;
  for (int i = 0; i < 3; i++)
    temp = temp * 10 + (lock[0][i+1] + lock[1][i+1]) % 10;
  return !(temp % 6);
}

void shift(int lock[5]) {
  for (int i = 0; i < 4; i++)
    swap(lock[i], lock[(i + 1) % 5]);
}

bool checkAll(int lock[2][5]) {
  //shift right
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (check(lock)) return true;
      shift(lock[1]);
    }
    if (check(lock)) return true;
    shift(lock[0]);
  }
  return false;
}

int main() {
  int lock[2][5];
  for (auto &i: lock)
    for (int &j: i)
      cin >> j;
  bool ch = checkAll(lock);
  if (ch) {
    cout << "Boro joloo :)";
  } else {
    cout << "Gir oftadi :(";
  }
  return 0;
}
