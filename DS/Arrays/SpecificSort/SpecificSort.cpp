#include <iostream>

using namespace std;

//Given an array A of positive integers. Your task is to sort them in such a 
//way that the first part of the array contains odd numbers sorted in 
//descending order, rest portion contains even numbers sorted in ascending 
//order.

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

int main(int nArgc, char** pArgv) {
	//The first line in the input contains the number of test cases
	size_t nNumberOfTestCases;
	cin >> nNumberOfTestCases;

	while (nNumberOfTestCases-- > 0) {
		//The next line contains the size of the array
		int nSize;
		cin >> nSize;

		//Now read the array data
		int* pArray = new int[nSize];
		for (int64_t i = 0; i < nSize; ++i) {
			cin >> pArray[i];
		}

		//We need to sort an array in such a way that all 
		//odd numbers are on the left in descending order
		//and even numbers are on the right in ascending order
		//First we iterate the array and arrange all the odd numbers on the
		//left and even numbers on the right
		//THen we sort the two halves separately first half in descending order
		//and the 2nd half in ascending order
		//while swapping need to track the index at which odd switches to even
		
		for (int j = 0, i = -1; j < nSize; ++j) {
			if (pArray[j] % 2 != 0) {
				//odd, so swap
				swap(pArray[++i], pArray[j]);
			}
		}

		int nSwitchIndex(0);
		for (int i = 0; i < nSize; ++i) {
			//Compare adjacent numbers
			//if they are even, odd
			if (i + 1 == nSize) {
				nSwitchIndex = nSize;
				break;
			}
			if ((pArray[i] % 2 != 0) && (pArray[i + 1] % 2 == 0)) {
				nSwitchIndex = i;
				break;
			}
		}

		//Now sort the two halves
		QuickSort(pArray, 0, nSwitchIndex, false);
		QuickSort(pArray, nSwitchIndex + 1, nSize - 1, true);
		
		for (int64_t i = 0; i < nSize; ++i) {
			cout << pArray[i] << " ";
		}

		cout << endl;
	}
	return 0;
}