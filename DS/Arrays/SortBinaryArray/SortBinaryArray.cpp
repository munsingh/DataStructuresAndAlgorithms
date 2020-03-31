#include <iostream>
#include <string.h>

using namespace std;
//Given a binary array A[] of size N. The task is to arrange array in 
//increasing order. Note: The binary array contains only 0 and 1.
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

		//count the number of 0s and then number of 1s and then repopulate
		//the array depending on the count
		int arrCount[2] = { 0 };	//1st element contains the count of 0
									//and 2nd element contains the count of 1s
		for (int i = 0; i < nSize; ++i) {
			arrCount[pArray[i]]++;
		}

		for (int i = 0; i < arrCount[0]; ++i) {
			pArray[i] = 0;
		}

		for (int i = arrCount[0]; i < nSize; ++i) {
			pArray[i] = 1;
		}


		for (int i = 0; i < nSize; ++i) {
			cout << pArray[i] << " ";
		}

		cout << endl;
		delete[] pArray;
		pArray = nullptr;
	}
	return 0;
}