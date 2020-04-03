#include <iostream>
using namespace std;

int64_t Partition(int* pArray, int64_t nLeft,
				  int64_t nRight, bool bAscending = true) {

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
void QuickSort(int* pArray, int64_t nLeft, 
			   int64_t nRight, bool bAscending = true) {
	if (nLeft >= nRight) {
		return;
	}

	int64_t nPartition = Partition(pArray, nLeft, nRight, bAscending);
	QuickSort(pArray, nLeft, nPartition - 1, bAscending);
	QuickSort(pArray, nPartition + 1, nRight, bAscending);
}
//Given an array of n elements. Consider array as circular array i.e element 
//after an is a1. The task is to find maximum sum of the difference between 
//consecutive elements with rearrangement of array element allowed i.e after 
//rearrangement of element find |a1 – a2| + |a2 – a3| + …… + |an – 1– an| + 
//|an – a1|.
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

		//We need to arrange the array in this manner
		//[min, max], [2ndmin, 2ndmax], [3rdmin, 3rdmax] and so on
		//then add the absolute delta of the pairs. For the last element
		//pair it with the 1st one, as it is a circular array

		//to do this we first sort the array,
		//so an array like 4 8 2 6 1 after sorting becomes
		//4 8 2 6 1 <- Before Sorting
		//1 2 4 6 8 <- After sorting
		//1 8 2 6 4 <- After rearrangemenent

		//so first sort in ascending order
		QuickSort(pArray, 0, nSize - 1);
		
		//now iterate the array from begining and end as long as begining is 
		//less than equal to end
		int *pTempArray = new int[nSize];
		int64_t nBegin(0), nEnd(nSize - 1);
		bool bToggle = true;
		for (int64_t i = 0; i < nSize; ++i) {
			pTempArray[i] = bToggle ? pArray[nBegin++] : pArray[nEnd--];
			bToggle = !bToggle;
		}
		
		int nSum(0);
		for (int64_t i = 0; i < nSize; ++i) {
			if (i + 1 == nSize) {
				nSum += abs(pTempArray[i] - pTempArray[0]);
			}
			else {
				nSum += abs(pTempArray[i] - pTempArray[i + 1]);
			}
		}

		cout << nSum << endl;
		delete[] pTempArray;
		pTempArray = nullptr;
		delete[] pArray;
		pArray = nullptr;
	}

	return 0;
}