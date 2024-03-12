#include <bits/stdc++.h>

using namespace std;

const char *AttackWord = "Attack";
const char *ButWord = "But";

size_t StrInStr(const char *, const char *, int);
size_t StrLen(const char *);

int main() {
  int matchedAttackLocations[20], matchedButLocations[20];
  string temp;
  cin >> temp;
  const char *Str = temp.c_str();
  int startIndex = 0, i;
  size_t foundLocation = StrInStr(Str, AttackWord, startIndex);
  for (i = 0; foundLocation != -1; i++) {
    startIndex = matchedAttackLocations[i] = foundLocation + 6;
    foundLocation = StrInStr(Str, AttackWord, startIndex);
  }
  int matchedAttackCount = i;
  startIndex = 0;
  foundLocation = StrInStr(Str, ButWord, startIndex);
  for (i = 0; foundLocation != -1; i++) {
    startIndex = matchedButLocations[i] = foundLocation + 3;
    foundLocation = StrInStr(Str, ButWord, startIndex);
  }
  int searchFirst = i ? matchedButLocations[i - 1] : 0, matched = 0, k;
  for (k = 0; k < matchedAttackCount; k++) {
    if (matchedAttackLocations[k] > searchFirst) {
      matched++;
    } else continue;
    if (matched == 2) {
      int integerIterator = matchedAttackLocations[k];
      while (Str[integerIterator] <= '9' && Str[integerIterator] >= '0')
        cout << Str[integerIterator++];
      return 0;
    }
  }
  int integerIterator = matchedAttackLocations[k - 1];
  while (Str[integerIterator] <= '9' && Str[integerIterator] >= '0')
    cout << Str[integerIterator++];
  return 0;
}

size_t StrInStr(const char *str, const char *substr, int startIndex) {
  size_t strLength = StrLen(str) - startIndex;
  size_t substrLen = StrLen(substr);
  if (strLength >= substrLen)
    for (int i = 0; i <= strLength - substrLen; i++) {
      int j;
      for (j = 0; j < substrLen; j++)
        if (str[i + j + startIndex] != substr[j]) break;
      if (j == substrLen) return i + startIndex;
    }
  return -1;
}

size_t StrLen(const char *str) {
  size_t i = 0;
  while (*str) {
    str++;
    i++;
  }
  return i;
}