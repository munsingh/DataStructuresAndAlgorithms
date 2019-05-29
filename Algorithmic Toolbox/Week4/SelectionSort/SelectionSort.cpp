#include <vector>
#include <iostream>


template <class T> void SelectionSortNaive(std::vector<T>& vecList) {
	size_t nSize = vecList.size();

	T nTemp;
	size_t nMinIndex = 0;
	bool bFound = false;
	for (size_t i = 0; i < nSize; ++i) {
		nMinIndex = i;
		bFound = false;
		for (size_t j = i + 1; j < nSize; ++j) { 
			if (vecList[nMinIndex] > vecList[j]) {
				nMinIndex = j;
				bFound = true;
			}
		}

		if (bFound) {
			//swap first and nMin
			nTemp = vecList[i];
			vecList[i] = vecList[nMinIndex];
			vecList[nMinIndex] = nTemp;
		}
	}
}

/*
 This implements Selection sort techniques. The way selection sort works is by finding out the lowest number in the element and swapping it with the first element
 FOr the next round the search starts from 2nd element and so on. In the end, the resulting list is sorted.
 */
int main(int nArgc, char** pArgv) {
	int nNumberOfElements;
	std::cin >> nNumberOfElements;

	std::vector< int > vecList(nNumberOfElements);

	for (int i = 0; i < nNumberOfElements; ++i) {
		std::cin >> vecList[i];
	}
	
	SelectionSortNaive(vecList);
	for (int i = 0; i < nNumberOfElements; ++i) {
		std::cout << vecList[i] << " ";
	}

	return 0;
}