#include <iostream>
#include <cmath>
using std::cout, std::cin, std::endl;

int main(){
  int n, m;
  cin >> n >> m;
  // allocate memory to chairs boolean array and initialize it to false values
  bool *chairs = new bool[n];
  for (int i = 0;i < n;i++)
    chairs[i] = false;
  while(m--) {
    int s, l;
    cin >> s >> l;
    // for working with arrays
    s--;
    // check availability
    int k = 0, iter = s;
    for (; iter < n && k < l; iter++)
      k = (chairs[iter]) ? 0 : k + 1;
    // enable chairs is available
    if (k >= l) {
      k = iter;
      iter -= l;
      for (; iter < k; iter++)
        chairs[iter] = true;
    }
    // print chairs
    for (int i = 0;i < n;i++)
      cout << (chairs[i] ? 1 : 0);
  } // End While
  delete[] chairs;
  return 0;
}