#include <iostream>
#include <vector>
#include <algorithm>

int MaxProduct(int n, const std::vector< int >& vecNumbers) {
	int nMaxProduct = 1;

	for (size_t i = 0; i < vecNumbers.size(); ++i) {
		for (size_t j = i + 1; j < vecNumbers.size(); ++j) {
			nMaxProduct = std::max(nMaxProduct, vecNumbers[i] * vecNumbers[j]);
		}
	}

	return nMaxProduct;
}

int main( int nArgc, char** pArgv ){
	int nNumberOfIntegers = 0;
	std::cin >> nNumberOfIntegers;

	std::vector< int > vecNumbers( nNumberOfIntegers );
	for (int i = 0; i < nNumberOfIntegers; ++i) {
		std::cin >> vecNumbers[ i ] ;
	}
	
	std::cout << MaxProduct(nNumberOfIntegers, vecNumbers);

	return 0;
}