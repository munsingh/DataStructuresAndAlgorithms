#include <iostream>
using namespace std;

//Given two sorted arrays. There is only 1 difference between the arrays. 
//First array has one element extra added in between. 
//Find the index of the extra element.
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
		int* pArray1 = new int[nSize];
		for (int64_t i = 0; i < nSize; ++i) {
			cin >> pArray1[i];
		}

		int* pArray2 = new int[nSize - 1];
		for (int64_t i = 0; i < nSize - 1; ++i) {
			cin >> pArray2[i];
		}

		//to find the index of the missing element
		//we iterate the two arrays simultaneously
		int64_t nIndex = nSize, nLeft = 0, nRight = nSize - 1;

		//use binary search for O(log n) complexity
		while (nLeft <= nRight) {
			int nMid = (nLeft + nRight) / 2;

			if (pArray1[nMid] == pArray2[nMid]) {
				//not within nLeft to nMid
				nLeft = nMid + 1;
			}
			else {
				//not equal
				nIndex = nMid;
				nRight = nMid - 1;
			}
		}

		cout << nIndex << endl;

		delete[] pArray2;
		pArray2 = nullptr;

		delete[] pArray1;
		pArray1 = nullptr;
	}

	return 0;
}