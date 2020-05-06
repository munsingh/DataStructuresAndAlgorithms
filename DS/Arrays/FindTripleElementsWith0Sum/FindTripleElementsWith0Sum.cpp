#include <iostream>
using namespace std;

int64_t Partition(int* pArray, int64_t nLeft, int64_t nRight, bool bAscending) {
	int nPivot = pArray[nLeft];
	int64_t nPartition = nLeft + 1;

	for (int64_t i = nLeft + 1; i <= nRight; ++i) {
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

void QuickSort(int* pArray, int64_t nLeft, int64_t nRight, bool bAscending) {
	if (nLeft >= nRight) {
		return;
	}

	int64_t nPartition = Partition(pArray, nLeft, nRight, bAscending);
	QuickSort(pArray, nLeft, nPartition - 1, bAscending);
	QuickSort(pArray, nPartition + 1, nRight, bAscending);
}

//Given an array A[] of N elements. The task is to complete the function which 
//returns true if triplets exists in array A whose sum is zero else returns 
//false.
int main(int nArgc, char** pArgv) {
	//The first line in the input contains the number of test cases
	int nNumberOfTestCases;
	cin >> nNumberOfTestCases;

	while (nNumberOfTestCases-- > 0) {
		//The next line contains the size of the array and the number
		//to whicht he closest value has to be found
		int64_t nSize;
		cin >> nSize;

		//Now read the array data
		int* pArray = new int[nSize];
		for (int64_t i = 0; i < nSize; ++i) {
			cin >> pArray[i];
		}

		//Sort the array first
		QuickSort(pArray, 0, nSize - 1, true);

		int nSum(0);
		bool bFound = false;

		for (int64_t i = 0; i < nSize - 1; ++i) {
			int64_t nLeft(i + 1), nRight(nSize - 1);
			int nElement = pArray[i];
			
			while (nLeft < nRight) {
				nSum = nElement + pArray[nLeft] + pArray[nRight];
				if ( nSum == 0) {
					bFound = true;
					nLeft++;
					nRight--;
				}
				else if (nSum > 0) {
					nRight--;
				}
				else if (nSum < 0) {
					nLeft++;
				}
				else {
					//should not come here
				}
			}
		}

		cout << bFound << endl;
		delete[] pArray;
		pArray = nullptr;
	}

	return 0;
}