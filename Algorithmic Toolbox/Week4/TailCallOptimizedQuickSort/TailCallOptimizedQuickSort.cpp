#include <vector>
#include <algorithm>
#include <random>
#include <iostream>
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
	while (nLeft < nRight) {
		int nPartition = Partition(vecList, nLeft, nRight);

		if (nPartition - nLeft < nRight - nPartition) {
			//Sort the left part recursively and right part iteratively
			QuickSort(vecList, nLeft, nPartition - 1);
			nLeft = nPartition + 1;
		}
		else {
			//Sort the right part recursively and left part iteratively
			QuickSort(vecList, nPartition + 1, nRight);
			nRight = nPartition - 1;
		}
	}
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
		std::cout << vecList[i] << " ";
	}

	return 0;
}