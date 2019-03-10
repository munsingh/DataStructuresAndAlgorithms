#include <iostream>

int main(int nArgv, char** pArgc) {
	int nHowMany = 0;
	std::cin >> nHowMany;

	//Generate fibonacci numbers uptill nHowMany numbers
	int nFminus2 = 1;
	int nFminus1 = 1;
	int nFibonacci = 0;


	for (int i = 0; i < nHowMany; ++i) {
		nFibonacci = nFminus1 + nFminus2;
		std::cout << nFibonacci << " ";
		nFminus1 = nFibonacci;
		nFminus2 = nFminus1;
	}

	return 0;
}