#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <time.h>

/*
This function we will find the two biggest number and calculate their sum.
*/
long long MaxProductFast(const std::vector< int >& vecNumbers) {
	//We find the index at which the maximum number is stored
	int nMaxIndex = -1;

	for (size_t i = 0; i < vecNumbers.size(); ++i) {
		if (nMaxIndex == -1 || vecNumbers[i] > vecNumbers[nMaxIndex]) {
			nMaxIndex = i;
		}
	}

	//Now find the index where the second largest number is stored
	//for this we use the same approach as above, except we compare the number with the largest as well
	//and it is 2ndlargest if it is less than the largest
	int nMaxIndex2 = -1;
	for (size_t i = 0; i < vecNumbers.size(); ++i) {
		if ( vecNumbers[i] != vecNumbers[nMaxIndex] && ( nMaxIndex2 == -1 || vecNumbers[i] > vecNumbers[nMaxIndex2] )) {
			nMaxIndex2 = i;
		}
	}

	return static_cast< long long >(vecNumbers[nMaxIndex]) * vecNumbers[nMaxIndex2];
}

//This function is slow and will work in O(n^2)
long long MaxProduct(const std::vector< int >& vecNumbers) {
	long long nMaxProduct = 1;

	for (size_t i = 0; i < vecNumbers.size(); ++i) {
		for (size_t j = i + 1; j < vecNumbers.size(); ++j) {
			nMaxProduct = std::max(nMaxProduct, static_cast< long long >( vecNumbers[i] ) * vecNumbers[j]);
		}
	}

	return nMaxProduct;
}

int main( int nArgc, char** pArgv ) {

	int nNumberOfIntegers = 0;
	std::cin >> nNumberOfIntegers;

	std::vector< int > vecNumbers( nNumberOfIntegers );
	for (int i = 0; i < nNumberOfIntegers; ++i) {
		std::cin >> vecNumbers[ i ] ;
	}
	
	std::cout << MaxProductFast( vecNumbers);

	//we generate random numbers and test it using both slow and fast
	/*srand(time(0));
	while (true) {
		
		int nNumberOfIntegers = rand() % 10 + 2;
		std::cout << nNumberOfIntegers << '\n';

		std::vector< int > vecNumbers;

		for (int i = 0; i < nNumberOfIntegers; ++i) {
			int nRandom = rand();
			vecNumbers.push_back(nRandom % 100000);

		}

		for (int i = 0; i < nNumberOfIntegers; ++i) {
			std::cout << vecNumbers[i] << " ";
		}

		std::cout << std::endl;

		long long lResult1 = MaxProduct(vecNumbers);
		long long lResult2 = MaxProductFast(vecNumbers);
		if (lResult1 != lResult2) {
			std::cout << "Wrong answer " << lResult1 << " " << lResult2 << std::endl;
			break;
		}
		else {
			std::cout << "Correct" << '\n';
		}
	}*/

	return 0;
}