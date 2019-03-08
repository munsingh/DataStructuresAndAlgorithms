#include <iostream>
#include <vector>
#include <algorithm>

long long MaxProduct(const std::vector< int >& vecNumbers) {
	long long nMaxProduct = 1;

	for (size_t i = 0; i < vecNumbers.size(); ++i) {
		for (size_t j = i + 1; j < vecNumbers.size(); ++j) {
			nMaxProduct = std::max(nMaxProduct, static_cast< long long >( vecNumbers[i] ) * vecNumbers[j]);
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
	
	std::cout << MaxProduct( vecNumbers);

	return 0;
}