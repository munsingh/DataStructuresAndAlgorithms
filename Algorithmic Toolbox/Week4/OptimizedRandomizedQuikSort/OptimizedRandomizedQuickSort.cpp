#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include <time.h>

template <class T> void Partition(std::vector<T>& vecList, int nLeft, int nRight, int& nPartition1, int& nPartition2) {
	//The values which are same as the pivot are between nPartition1 and nPartition2
	//TO handle the 2 elements
	if (nRight - nLeft < 2) {
		if (vecList[nRight] < vecList[nLeft]) {
			std::swap(vecList[nRight], vecList[nLeft]);
		}
		nPartition1 = nLeft;
		nPartition2 = nRight;
		return;
	}

	int i = nLeft;
	int nPivot = vecList[nRight];
	while (i <= nRight) {
		if (nPivot > vecList[i]) {
			std::swap(vecList[nLeft++], vecList[i++]);
		}
		else if (nPivot < vecList[i]) {
			std::swap(vecList[i], vecList[nRight--]);
		}
		else {
			i++;
		}
	}

	nPartition1 = nLeft - 1;
	nPartition2 = i;
}

template <class T> void QuickSort(std::vector<T>& vecList, int nLeft, int nRight) {
	if (nLeft >= nRight)
		return;

	std::mt19937 oRng;
	oRng.seed(static_cast< unsigned int >(time(NULL)));
	std::uniform_int_distribution<T> oDist(nLeft, nRight);
	int nRandom = oDist(oRng);
	std::swap(vecList[nRandom], vecList[nLeft]);

	int nPartition1, nPartition2;
	Partition(vecList, nLeft, nRight, nPartition1, nPartition2);
	QuickSort(vecList, nLeft, nPartition1);
	QuickSort(vecList, nPartition2, nRight);
}

int main(int /*nArgv*/, char** /*pArgc*/) {
	//get the number of elements
	int nNumberOfElements = 0;
	std::cin >> nNumberOfElements;

	std::vector<int> vecList(nNumberOfElements);
	for (int i = 0; i < nNumberOfElements; i++) {
		std::cin >> vecList[i];
	}

	QuickSort(vecList, 0, nNumberOfElements - 1);
	for (int i = 0; i < nNumberOfElements; i++) {
		std::cout << vecList[i] << " ";
	}
	return 0;
}