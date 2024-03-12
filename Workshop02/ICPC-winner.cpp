#include <bits/stdc++.h>

using namespace std;
bool isMatch(const string &original, const string &fake);

int main() {
  string original, fake;
  cin >> original;
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cin >> fake;
    if (isMatch(original, fake)) {
      cout << "The winner is the " << i << "th player of the list";
      return 0;
    }
  }
  cout << "The winner was not in the input list";
  return 0;
}

bool isMatch(const string &original, const string &fake) {
  size_t findMinIndex = 0;
  int findStart = 0, findLength = 0;
  auto findLambda = [&original, &fake, &findStart, &findLength, &findMinIndex]() {
      return original.find(
              fake.substr(findStart, findLength),
              findMinIndex);
  };
  for (int i = 0; i < fake.length(); i++) {
    if (fake[i] == '?') {
      auto findResult = findLambda();
      if (findResult == string::npos) return false;
      findMinIndex = findResult + findLength;
      findStart = i + 1, findLength = 0;
    } else findLength++;
  }
  if (findLength) {
    auto findResult = findLambda();
    if (findResult != string::npos)
      return findResult + findLength == original.length();
    return false;
  }
  return true;
}
