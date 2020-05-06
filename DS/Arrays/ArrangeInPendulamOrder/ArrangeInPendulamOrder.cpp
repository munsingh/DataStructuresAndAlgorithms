#include <iostream>
#include <limits.h>
using namespace std;

int64_t Partition(int* pArray,
					int64_t nLeft,
					int64_t nRight,
					bool bAscending = true) {
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

void QuickSort(int* pArray, 
				int64_t nLeft, 
				int64_t nRight, 
				bool bAscending = true) {
	if (nLeft >= nRight)
		return;

	int64_t nPartition = Partition(pArray, nLeft, nRight, bAscending);
	QuickSort(pArray, nLeft, nPartition - 1, bAscending);
	QuickSort(pArray, nPartition + 1, nRight, bAscending);
}

//Write a program to input a list of n integers in an array and arrange them 
//in a way similar to the to-and-fro movement of a Pendulum.

//The minimum element out of the list of integers, must come in center 
//position of array.If there are even elements, then minimum element should be 
//moved to(n - 1) / 2 index (considering that indexes start from 0)
//The next number(next to minimum) in the ascending order, goes to the right, 
//the next to next number goes to the left of minimum number and it continues 
//like a Pendulum.
int main(int nArgc, char** pArgv) {
	//The first line in the input contains the number of test cases
	int nNumberOfTestCases;
	cin >> nNumberOfTestCases;

	while (nNumberOfTestCases-- > 0) {
		//The next line contains the size of the array
		int64_t nSize;
		cin >> nSize;

		//Now read the array data
		int* pArray = new int[nSize];
		for (int64_t i = 0; i < nSize; ++i) {
			cin >> pArray[i];
		}

		//First sort the array
		QuickSort(pArray, 0, nSize - 1);

		//Keep track of the minimum element
		int nMin = pArray[0];
		//Element one greater than minimum will go at center + 1 location
		//Next greater element will go and center -1
		//next will go at center + 2
		//next will go at center - 2
		int* pTempArray = new int[nSize];
		int64_t nCenter = (nSize - 1) / 2;
		int64_t nDelta = 1, nIndex = 1;
		for (; nDelta <= nCenter; ++nDelta) {
			pTempArray[nCenter + nDelta] = pArray[nIndex++];
			pTempArray[nCenter - nDelta] = pArray[nIndex++];
		}

		pTempArray[nCenter] = nMin;
		if (nSize % 2 == 0) {
			//size is even
			pTempArray[nCenter + nDelta] = pArray[nIndex];
		}

		for (int64_t i = 0; i < nSize; ++i) {
			cout << pTempArray[i] << " ";
		}

		cout << endl;

		delete[] pTempArray;
		pTempArray = nullptr;
		delete[] pArray;
		pArray = nullptr;
	}

	return 0;
}