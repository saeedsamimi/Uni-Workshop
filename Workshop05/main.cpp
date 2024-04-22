#include <iostream>

using namespace std;

class F;

class K {
public:
  explicit K(const string &&dic) : DicK(dic) {}
  
  friend string getAllDices(const K &, const F &);
private:
  string DicK;
};

class F {
public:
  explicit F(const string &&dic) : DicF(dic) {}
  
  friend string getAllDices(const K &, const F &);
private:
  string DicF;
};

string getAllDices(const K &KObj, const F &FObj);

int main() {
  K kDices("A,B,C,D");
  F fDices("C,G,H,M");
  cout << "All dices is: " << getAllDices(kDices, fDices) << endl;
}

string getAllDices(const K &KObj, const F &FObj) {
  return KObj.DicK + ',' + FObj.DicF;
}
