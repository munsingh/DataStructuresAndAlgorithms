#include <iostream>
#include <string.h>

using namespace std;
//You are given an array A[], you have to construct a new array A2[].
//The values in A2[] are obtained by doing OR of consecutive elements in array.
int main(int nArgc, char** pArgv) {
	//The first line in the input contains the number of test cases
	size_t nNumberOfTestCases;
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

		int *pNewArray = new int[nSize];

		for (int64_t i = 0; i < nSize; ++i) {
			if (i + 1 == nSize) {
				pNewArray[i] = pArray[i];
			}
			else {
				pNewArray[i] = pArray[i] | pArray[i + 1];
			}
		}

		for (int64_t i = 0; i < nSize; ++i) {
			cout << pNewArray[i] << " ";
		}

		cout << endl;
		delete[] pNewArray;
		pNewArray = nullptr;
		delete[] pArray;
		pArray = nullptr;
	}
	return 0;
}