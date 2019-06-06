#include <vector>
#include <algorithm>
#include <random>
#include <iostream>
#include <time.h>

template <class T> void Partition(std::vector<T>& vecList, int nLeft, int nRight, int nPartition1, int nPartition2) {
	T	nPivot = vecList[nLeft];
	int nPartition1 = nLeft + 1;
	int nPartition2 = nRight;
	int i = nLeft + 1;

	while (i <= nRight) {
		if (nPivot > vecList[i]) {
			std::swap(vecList[i++], vecList[nPartition1++]);
		}
		else if (nPivot < vecList[i]) {
			std::swap(vecList[i], vecList[nPartition2--])
		}
		else {
			//nPivot == vecList[i];
			i++
		}
	}

	//find the minimum
	int nMinimum = std::min(nPartition2 - nPartition1, nRight - nPartition2 + 1);
	for (int i = 0; i < nMinimum; i++) {
		std::swap(vecList[nPartition1 + 1], vecList[nRight - nMinimum + 1 + i]);
	}
}

template <class T> void QuickSort(std::vector<T>& vecList, int nLeft, int nRight) {

}

int main(int /*nArgv*/, char** /*pArgc*/) {
	//get the number of elements
	int nNumberOfElements;

	std::cin >> nNumberOfElements;

	std::vector<int> vecList(nNumberOfElements);
	for (int i = 0; i < nNumberOfElements; ++i) {
		std::cin >> vecList[i];
	}

	QuickSort(vecList, 0, nNumberOfElements - 1);
	for (int i = 0; i < nNumberOfElements; ++i) {
		std::cout << vecList[i];
	}

	return 0;
}