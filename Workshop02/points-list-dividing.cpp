#include <bits/stdc++.h>

using namespace std;

int *partition(int *, int *);
void quickSort(int *, int *);
void swap(int *, int *);

int main() {
  int n;
  cin >> n;
  int *A = new int[n];
  int *iterator = A;
  int *end = A + n;
  while (iterator < end)
    cin >> *iterator++;
  quickSort(A, end - 1);
  iterator = A;
  const int *middle = iterator + (n / 2);
  while (iterator < middle)
    cout << *iterator++ << " ";
  cout << endl;
  while (iterator < end)
    cout << *iterator++ << " ";
  return 0;
}

int *partition(int *start, int *end) {
  int *j = end - 1;
  while (j >= start) {
    if (*start > *end)
      swap(start--, j--);
    start++;
  }
  swap(start, end);
  return start;
}

void swap(int *A, int *B) {
  if (*A != *B) {
    *A ^= *B;
    *B ^= *A;
    *A ^= *B;
  }
}

void quickSort(int *start, int *end) { //NOLINT(misc-no-recursion)
  if (end > start) {
    int *p = partition(start, end);
    quickSort(start, p - 1);
    quickSort(p + 1, end);
  }
}
