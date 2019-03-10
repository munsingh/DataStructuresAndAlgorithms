#include <iostream>

int main(int nArgv, char** pArgc) {
	int nHowMany = 0;
	std::cin >> nHowMany;

	long long nFMinus2 = 0;
	long long nFMinus1 = 1;
	long long nFibonacci = 0;

	std::cout << nFMinus2 << " " << nFMinus1 << " ";

	for (int i = 0; i <  nHowMany - 2; ++i) {
		nFibonacci = nFMinus1 + nFMinus2;
		std::cout << nFibonacci << " ";
		nFMinus2 = nFMinus1;
		nFMinus1 = nFibonacci;
	}

	return 0;
}