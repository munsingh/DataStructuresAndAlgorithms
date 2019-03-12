#include <iostream>

int FibonacciLastDigit(int n) {
	//Instead of generating the fibonacci number, we will sum up the last digits of the fibonacci numbers
	if (n <= 1)
		return n;
	int nFMinus2LastDigit = 0;
	int nFMinus1LastDigit = 1;
	int nFibonacciLastDigit = 0;

	for (int i = 1; i < n; ++i) {
		nFibonacciLastDigit = nFMinus1LastDigit + nFMinus2LastDigit;
		nFibonacciLastDigit = nFibonacciLastDigit % 10;
		nFMinus2LastDigit = nFMinus1LastDigit;
		nFMinus1LastDigit = nFibonacciLastDigit;
	}

	return nFibonacciLastDigit;
}

int main(int nArgv, char** pArgc) {
	//read the nth number whose fibonacci's last number has to be stored.
	int n;
	std::cin >> n;

	std::cout << FibonacciLastDigit(n);

	return 0;
}