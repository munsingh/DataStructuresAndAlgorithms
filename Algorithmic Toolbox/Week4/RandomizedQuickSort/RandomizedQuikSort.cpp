#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include <time.h>

template <class T> int Partition(std::vector<T>& vecList, int nLeft, int nRight) {
	T nPivot = vecList[nLeft];
	int nPartition = nLeft + 1;

	for (int i = nLeft + 1; i <= nRight; ++i) {
		if (nPivot > vecList[i]) {
			std::swap(vecList[nPartition], vecList[i]);
			nPartition++;
		}
	}
	std::swap(vecList[nPartition - 1], vecList[nLeft]);
	return nPartition - 1;
}

template <class T> void QuickSort(std::vector<T>& vecList, int nLeft, int nRight) {
	if (nLeft >= nRight)
		return;

	std::mt19937 rng;
	rng.seed(time(NULL));

	std::uniform_int_distribution<T> oDist(nLeft, nRight);

	int nRandomNumber = oDist(rng);
	std::swap(vecList[nRandomNumber], vecList[nLeft]);
	int nPartition = Partition(vecList, nLeft, nRight);

	QuickSort(vecList, nLeft, nPartition - 1);
	QuickSort(vecList, nPartition + 1, nRight);
}

int main(int /*nArgv*/, char** /*pArgc*/) {
	//get the number of elements
	int nNumberOfElements = 0;
	std::cin >> nNumberOfElements;

	std::vector< int > vecList(nNumberOfElements);
	for (int i = 0; i < nNumberOfElements; ++i) {
		std::cin >> vecList[i];
	}

	QuickSort(vecList, 0, nNumberOfElements - 1);
	
	for (int i = 0; i < nNumberOfElements; ++i) {
		std::cout << vecList[i] << " ";
	}

	return 0;
}