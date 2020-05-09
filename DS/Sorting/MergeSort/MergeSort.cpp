#include <iostream>

using namespace std;

void Merge(int* pArray, int64_t nLeft, int64_t nMid, int64_t nRight) {
	//In this function we create two arrays, pLeft and pRight
	//pLeft will contain data from nLeft to nMid
	//and pRight will contain elements from nMid + 1 to nRight
	//elements from the pArray
	//The way to approach is as long as we have data to iterate in
	//both left and right array we keep iterating
	//while iterating we compare he 1st element of left with 
	//1st element of right
	//if left is less than or equal to right
	//then we move from left to end of pArray
	//else we move from right to the end of pArray

	//once iteration is complete
	//copy the remaining elements of left and right to end of pArray

	int64_t nLeftSize = nMid - nLeft + 1;
	int* pLeft = new int[nLeftSize];

	int64_t nRightSize = nRight - nMid;
	int* pRight = new int[nRightSize];

	//now copy the contents of pArray from nLeft to nMid to pLeft Array
	for (int64_t i = 0; i < nLeftSize; ++i) {
		pLeft[i] = pArray[nLeft + i];
	}

	//now copy the contents of pArray from nMid + 1 to nRight to pRight Array
	for (int64_t i = 0; i < nRightSize; ++i) {
		pRight[i] = pArray[nMid + 1 + i];
	}

	int64_t i = 0, j = 0, k = nLeft;

	while (i < nLeftSize && j < nRightSize) {
		//if left is less than equal to right, then put
		//left in the pArray
		if (pLeft[i] <= pRight[j]) {
			pArray[k] = pLeft[i];
			++i;
		}
		else {
			pArray[k] = pRight[j];
			++j;
		}
		++k;
	}

	//Now copy over the remainging left array contents to pArray
	while (i < nLeftSize) {
		pArray[k] = pLeft[i];
		k++;
		i++;
	}

	//Now copy over the remaining right array contents to pArray
	while (j < nRightSize) {
		pArray[k] = pRight[j];
		k++;
		j++;
	}

	delete[] pRight;
	pRight = nullptr;
	delete[] pLeft;
	pLeft = nullptr;
}

void MergeSort(int* pArray, int64_t nLeft, int64_t nRight) {
	if (nLeft < nRight) {
		int64_t nMid = nLeft + (nRight - nLeft) / 2;

		//sort left and right halves
		MergeSort(pArray, nLeft, nMid);
		MergeSort(pArray, nMid + 1, nRight);

		//merge them
		Merge(pArray, nLeft, nMid, nRight);
	}
}

//The task is to complete merge() function which is used to implement Merge 3
//Sort.
int main() {
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

		MergeSort(pArray, 0, nSize - 1);

		for (int64_t i = 0; i < nSize; ++i) {
			cout << pArray[i] << " ";
		}

		cout << endl;
		delete[] pArray;
		pArray = nullptr;
	}

	return 0;
}