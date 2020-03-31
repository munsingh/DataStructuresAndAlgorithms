#include <iostream>

using namespace std;

//Given an array Arr[] of N integers. Write a program to find out number of 
//pairs in array whose XOR is odd.
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

		int nCount(0);
		for (int i = 0; i < nSize; ++i) {
			for (int j = i + 1; j < nSize; ++j) {
				if ((pArray[i] ^ pArray[j]) % 2 != 0) {
					nCount++;
				}
			}
		}

		cout << nCount << endl;
	}
	return 0;
}