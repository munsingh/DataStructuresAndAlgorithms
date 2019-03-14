#include <iostream>

long long GetFibonacciHugeFast(long long lN, long long lM) {

	return 0;
}

long long GetFibonacciHugeNaive(long long lN, long long lM) {

	if (lN <= 1)
		return lN % lM;

	long long lFMinus2 = 0;
	long long lFMinus1 = 1;
	long long lFibonacci = 0;

	for (long long i = 1; i < lN; ++i) {
		lFibonacci = lFMinus1 + lFMinus2;
		lFMinus2 = lFMinus1;
		lFMinus1 = lFibonacci;
	}

	return lFibonacci % lM;
}

int main(int nArgv, char** pArgc) {
	long long lN, lM;

	std::cin >> lN >> lM;
	std::cout << GetFibonacciHugeNaive(lN, lM);

	return 0;
}