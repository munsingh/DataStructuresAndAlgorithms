#include <iostream>
using namespace std;

int Partition(int* pArray, int nLeft, int nRight, bool bAscending = true) {
	int nPivot = pArray[nLeft];
	int nPartition = nLeft + 1;

	for (int i = nLeft + 1; i <= nRight; ++i) {
		if (bAscending) {
			if (nPivot > pArray[i]) {
				swap(pArray[nPartition++], pArray[i]);
			}
		}
		else {
			if (nPivot < pArray[i]) {
				swap(pArray[nPartition++], pArray[i]);
			}
		}
	}
	swap(pArray[nPartition - 1], pArray[nLeft]);
	return nPartition - 1;
}

void QuickSort(int* pArray, int nLeft, int nRight, bool bAscending = true) {
	if (nLeft >= nRight)
		return;

	int nPartition = Partition(pArray, nLeft, nRight, bAscending);
	QuickSort(pArray, nLeft, nPartition - 1, bAscending);
	QuickSort(pArray, nPartition + 1, nRight, bAscending);
}

//You are given two arrays, A and B, of equal size N. The task is to find the 
//minimum value of A[0] * B[0] + A[1] * B[1] +…+ A[N-1] * B[N-1], where 
//shuffling of elements of arrays A and B is allowed.
int main(int argc, char** pArgv) {
	size_t nNumberOfInputs;
	cin >> nNumberOfInputs;

	while (nNumberOfInputs--) {
		int nSize;
		cin >> nSize;

		int* pArray1 = new int[nSize];
		for (int i = 0; i < nSize; ++i) {
			cin >> pArray1[i];
		}

		int* pArray2 = new int[nSize];
		for (int i = 0; i < nSize; ++i) {
			cin >> pArray2[i];
		}

		//for calculating the minimum value of products we should first
		//sort the array in ascending order
		QuickSort(pArray1, 0, nSize - 1);
		QuickSort(pArray2, 0, nSize - 1, false);

		int64_t nSum(0);
		for (int i = 0; i < nSize; ++i) {
			nSum += (pArray1[i] * pArray2[i]);
		}

		delete[] pArray2;
		pArray2 = nullptr;
		delete[] pArray1;
		pArray1 = nullptr;

		cout << nSum << endl;
	}

	return 0;
}