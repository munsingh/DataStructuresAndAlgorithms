#include <iostream>
#include <stdlib.h>
using namespace std;
//Given an array A of n integers, find the sum of f(a[i], a[j]) of all 
//pairs(i, j) such that(1 <= i < j <= n).
//	f(a[i], a[j]) : If | a[j] - a[i] | > 1
//
//	f(a[i], a[j]) = a[j] - a[i]
//
//	Else  if | a[j] - a[i] | <= 1
//
//	f(a[i], a[j]) = 0
// For example for an array of 6 6 4 4, the pairs are
//(6 - 6) + (4 - 6) + (4 - 6) + (4 - 6) + (4 - 6) + (4 - 4) = -8

int Partition(int* pArray, int nLeft, int nRight) {
	int nPivot = pArray[nLeft];
	int nPartition = nLeft + 1;
	for (int i = nLeft + 1; i <= nRight; ++i) {
		if (nPivot > pArray[i]) {
			swap(pArray[nPartition++], pArray[i]);
		}
	}

	swap(pArray[nPartition - 1], pArray[nLeft]);
	return nPartition - 1;
}

void QuickSort(int* pArray, int nLeft, int nRight) {
	if (nLeft >= nRight)
		return;

	int nPartition = Partition(pArray, nLeft, nRight);
	QuickSort(pArray, nLeft, nPartition - 1);
	QuickSort(pArray, nPartition + 1, nRight);
}

int main(int argc, char** pArgv) {
	size_t nNumberOfInputs;
	cin >> nNumberOfInputs;

	while (nNumberOfInputs--) {
		int nSize;
		cin >> nSize;

		int* pArray = new int[nSize];
		for (int i = 0; i < nSize; ++i) {
			cin >> pArray[i];
		}

		//to create pairs such that i < j, the right approach would be to sort
		//the array, we will use quick sort in our case
		QuickSort(pArray, 0, nSize - 1);
		//now iterate the array which will be in sorted order e.g.
		//4 4 6 6
		int nSum(0);

		for (int i = 0; i < nSize; ++i) {
			for (int j = i + 1; j < nSize; ++j) {
				if (pArray[j] - pArray[i] > 1) {
					nSum += pArray[j] - pArray[i];
				}
			}
		}
		cout << nSum << endl;
		delete[] pArray;
	}

	return 0;
}