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

void qSort(int A[], int start, int end) {
	if (end > start) {
		int i = start, j = end - 1, temp;
		while (j >= i)
			if (A[i] > A[end]) {
				temp = A[i];
				A[i--] = A[j];
				A[j--] = temp;
			}
			else i++;
		temp = A[end];
		A[end] = A[i];
		A[i] = temp;
		qSort(A, start, i - 1);
		qSort(A, i + 1, end);
	}
}
