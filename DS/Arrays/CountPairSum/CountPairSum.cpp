#include <iostream>

using namespace std;

//Given two sorted arrays of size m and n of distinct elements. Given a value 
//x. The problem is to count all pairs from both arrays whose sum is equal to 
//x.
//Note: The pair has an element from each array.
int main(int nArgc, char** pArgv) {
	//The first line in the input contains the number of test cases
	int nNumberOfTestCases;
	cin >> nNumberOfTestCases;

	while (nNumberOfTestCases-- > 0) {
		//The next line contains the size of the array
		int64_t nSize1, nSize2;
		cin >> nSize1 >> nSize2;

		//Now read the array data
		int* pArray1 = new int[nSize1];
		for (int64_t i = 0; i < nSize1; ++i) {
			cin >> pArray1[i];
		}

		int* pArray2 = new int[nSize2];
		for (int64_t i = 0; i < nSize2; ++i) {
			cin >> pArray2[i];
		}

		int nSum;
		cin >> nSum;

		int64_t nCount(0);

		for (int64_t i = 0; i < nSize1; ++i) {
			for (int64_t j = 0; j < nSize2; ++j) {
				if (pArray1[i] + pArray2[j] == nSum) {
					++nCount;
				}
			}
		}

		cout << nCount << endl;
		delete[] pArray2;
		pArray2 = nullptr;
		delete[] pArray1;
		pArray1 = nullptr;
	}

	return 0;
}