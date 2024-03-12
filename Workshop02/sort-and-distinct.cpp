#include <bits/stdc++.h>

using namespace std;

int *partition(int *, int *);
void quickSort(int *, int *);
void swap(int *, int *);
size_t distinct(int *, int *);

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
  while (iterator < end)
    cout << *iterator++ << " ";
  cout << endl;
  size_t newN = distinct(A, end);
  iterator = A;
  end = A + newN;
  while (iterator < end)
    cout << *iterator++ << " ";
  delete[] A;
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

size_t distinct(int *start, int *end) {
  for (int *i = start; i < end; i++) {
    int countDuplicates, *k;
    for (k = i + 1, countDuplicates = 0; k < end && *k == *i; countDuplicates++, k++);
    // fall back
    while (k < end) {
      *(k - countDuplicates) = *k;
      k++;
    }
    end -= countDuplicates; // decrease real count
  }
  return end - start;
}