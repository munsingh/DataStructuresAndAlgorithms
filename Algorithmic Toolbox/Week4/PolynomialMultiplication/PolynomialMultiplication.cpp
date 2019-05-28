#include <iostream>
#include <vector>

int PolynomialMultiplicationNaive(const std::vector< int >& vecA, const std::vector< int >& vecB, std::vector< int >& vecResult) {
	size_t nSizeA = vecA.size();
	size_t nSizeB = vecB.size();

	for (size_t i = 0; i < nSizeA; ++i) {
		for (size_t j = 0; j < nSizeB ; ++j) {
			vecResult[i + j] += vecA[i] * vecB[j];
		}
	}

	return 0;
}

int PolynomialMultplicationDAndRNaive(const std::vector<int>& vecA, const std::vector<int>& vecV, std::vector<int>& vecResult, int nNumberOfCoefficients, int nMin, int mMax) {
	//TBD
	return 0;
}

int main(int nArgc, char** pArgv) {
	//Read the number of coefficients
	int nNumberOfCoefficients = 0;
	std::cin >> nNumberOfCoefficients;

	//Now read the first set of coefficients
	std::vector<int> vecA(nNumberOfCoefficients, 0);
	std::vector<int> vecB(nNumberOfCoefficients, 0);

	for (size_t i = 0; i < nNumberOfCoefficients; ++i) {
		std::cin >> vecA[i];
	}

	for (size_t i = 0; i < nNumberOfCoefficients; ++i) {
		std::cin >> vecB[i];
	}

	std::vector<int> vecResult(2 * nNumberOfCoefficients - 1, 0);

	PolynomialMultiplicationNaive(vecA, vecB, vecResult);
	for (size_t i = 0; i < vecResult.size(); ++i) {
		std::cout << vecResult[i] << " ";
	}
	std::cout << "\n";


	//Call the Divide and Rule Naive algorithm
	std::fill(vecResult.begin(), vecResult.end(), 0);
	//PolynomialMultplicationDAndRNaive( vecA, vecB, vecResult, nNumberOfCoefficients, )

}