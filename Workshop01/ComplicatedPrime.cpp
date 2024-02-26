#include <iostream>
#include <cmath>
using std::cout, std::cin, std::endl, std::sqrt, std::floor;

int reverse(int);
bool isPrime(int);

int main(){
	int n;
	cin >> n;
	cout << (isPrime(n) && isPrime(reverse(n)));
	return 0;
}

int reverse(int n) {
	int temp = 0;
	while (n > 0) {
		temp = temp * 10 + n % 10;
		n /= 10;
	}
	return temp;
}

bool isPrime(int n) {
  if (n == 1) return false;
  if (n % 2 == 0) return n == 2;
  const int S = floor(sqrt(n));
  for (int i = 3; i <= S; i += 2)
    if (n % i == 0) return false;
  return true;
}