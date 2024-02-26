#include <iostream>
using std::cout, std::cin, std::endl;

void qSort(int A[], int start, int end);

int main(){
	int n;
	cin >> n;
	int *A = new int[n];
	for (int i = 0;i < n;i++)
		cin >> A[i];
	qSort(A, 0, n-1);
	for (int i = 0;i < n;i++)
		cout << A[i] << " ";
	delete[] A;
	return 0;
}

void swap(int &A,int &B){
  int temp = A;
  A = B;
  B = temp;
}

void qSort(int A[], int start, int end) { // NOLINT(misc-no-recursion)
	if (end > start) {
		int i = start, j = end - 1;
		while (j >= i)
			if (A[i] > A[end])
        swap(A[i--],A[j--]);
			else i++;
    swap(A[end],A[i]);
		qSort(A, start, i - 1);
		qSort(A, i + 1, end);
	}
}
