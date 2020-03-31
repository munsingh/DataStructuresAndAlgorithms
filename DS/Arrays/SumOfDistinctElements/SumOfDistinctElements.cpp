#include <iostream>

using namespace std;

size_t Partition(int* pArray, size_t nLeft, size_t nRight) {
	int nPivot = pArray[nLeft];
	size_t nPartition = nLeft + 1;

	for (size_t i = nLeft + 1; i <= nRight; ++i) {
		if (nPivot > pArray[i]) {
			std::swap(pArray[nPartition++], pArray[i]);
		}
	}

	std::swap(pArray[nPartition - 1], pArray[nLeft]);

	return nPartition - 1;
}

void QuickSort(int *pArray, size_t nLeft, size_t nRight) {
	if (nLeft >= nRight)
		return;

	size_t nPartition = Partition(pArray, nLeft, nRight);

	QuickSort(pArray, nLeft, nPartition);
	QuickSort(pArray, nPartition + 1, nRight);
}

//Given an array of n elements such that every element of array is an integer 
//in the range 1 to n, find the sum of all the distinct elements of the array.
int main() {
	//The first line in the input contains the number of test cases
	int nNumberOfTestCases;
	cin >> nNumberOfTestCases;

	while (nNumberOfTestCases-- > 0) {
		//The next line contains space separated size of the array
		size_t nSize;
		cin >> nSize;

		//Now read the array data
		int* pArray = new int[nSize];
		for (size_t i = 0; i < nSize; ++i) {
			cin >> pArray[i];
		}

		//We sort the array using QuickSort
		//then it becomes easy to track of last unique array
		QuickSort(pArray, 0, nSize - 1);

		//iterate the array
		bool bUnique = false;
		int  nLastUniqueElement = pArray[0];
		int  nSum = nLastUniqueElement;

		for (int i = 1; i < nSize; ++i) {
			if (pArray[i] != nLastUniqueElement) {
				nLastUniqueElement = pArray[i];
				nSum += nLastUniqueElement;
			}
		}

		cout << nSum << endl;

		delete[] pArray;
		pArray = nullptr;
	}
	return 0;
}