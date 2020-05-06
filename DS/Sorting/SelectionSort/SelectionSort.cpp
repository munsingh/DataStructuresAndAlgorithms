#include <iostream>
#include <sstream>
#include <string>

using namespace std;

//The task is to complete select() function which is used to implement 
//Selection Sort.
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

		//Selection sort works by iterating the array and looking for the
		//smallest number in the array
		//teh smallest number is swapped with the first element where the
		//iteration starts
		int64_t nMinIndex = INT64_MAX;
		for (int64_t i = 0; i < nSize; ++i) {
			nMinIndex = i;
			for (int64_t j = i + 1; j < nSize; ++j) {
				if (pArray[j] < pArray[nMinIndex]) {
					nMinIndex = j;
				}
			}
			swap(pArray[i], pArray[nMinIndex]);
		}

		for (int64_t i = 0; i < nSize; ++i) {
			cout << pArray[i] << " ";
		}

		cout << endl;
		delete[] pArray;
		pArray = nullptr;
	}

	return 0;
}