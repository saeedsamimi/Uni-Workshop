#include <iostream>
#include <vector>

using namespace std;

int analyzeString(string &str) {
  vector<int> list;
  vector<char> method;
  string temp;
  for (char c: str) {
    if (c >= '0' && c <= '9')
      temp += c;
    else if (!temp.empty()) {
      list.push_back(stoi(temp));
      temp.clear();
    }
    if (c == '*' || c == '+')
      method.push_back(c);
  }
  if (!temp.empty())
    list.push_back(stoi(temp));
  // enable * 's
  vector<int> secondaryList;
  int T = list[0];
  for (int i = 0; i < method.size(); i++) {
    if (method[i] == '+') {
      secondaryList.push_back(T);
      T = list[i + 1];
    } else {
      T *= list[i + 1];
    }
  }
  secondaryList.push_back(T);
  int s = 0;
  for(auto i : secondaryList)
    s += i;
  return s;
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    string tmp;
    cin >> tmp;
    cout << analyzeString(tmp) << endl;
  }
  return 0;
}
