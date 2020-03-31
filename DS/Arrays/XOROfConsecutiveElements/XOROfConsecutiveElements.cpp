#include <iostream>

using namespace std;

// You are given an array A[], you have to construct a new array A2[].
// The values in A2[] are obtained by doing Xor of consecutive elements in 
// array.
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

		int* pXORArray = new int[nSize];

		for (int i = 0; i < nSize; ++i) {
			if (i + 1 == nSize) {
				pXORArray[i] = pArray[i];
			}
			else {
				pXORArray[i] = pArray[i] ^ pArray[i + 1];
			}
		}

		for (size_t i = 0; i < nSize; ++i) {
			cout << pXORArray[i] << " ";
		}

		cout << endl;
		delete[] pXORArray;
		pXORArray = nullptr;

		delete[] pArray;
		pArray = nullptr;
	}
	return 0;
}