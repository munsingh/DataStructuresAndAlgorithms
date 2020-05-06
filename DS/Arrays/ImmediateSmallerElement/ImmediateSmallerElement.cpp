#include <iostream>
using namespace std;

//Given an integer array of size N. For each element in the array, check 
//whether the right adjacent element (on the next immediate position) of the 
//array is smaller. If next element is smaller, print that element. 
//If not, then print -1.
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
		int* pArray = new int[nSize];
		for (int64_t i = 0; i < nSize; ++i) {
			cin >> pArray[i];
		}

		for (int64_t i = 0; i < nSize; ++i) {
			if (i + 1 == nSize) {
				cout << -1 << " ";
				break;
			}

			if (pArray[i] > pArray[i + 1]) {
				cout << pArray[i + 1] << " ";
			}
			else {
				cout << -1 << " ";
			}
		}

		cout << endl;
		delete[] pArray;
		pArray = nullptr;
	}

	return 0;
}