#include <iostream>

using namespace std;

int main(int nArgc, char** pArgv) {
	//The first line in the input contains the number of test cases
	int nNumberOfTestCases;
	cin >> nNumberOfTestCases;


	while (nNumberOfTestCases-- > 0) {
		//The next line contains the size of the array
		int nSize;
		cin >> nSize;

		//Now read the array data
		int* pArray = new int[nSize];
		for (size_t i = 0; i < nSize; ++i) {
			cin >> pArray[i];
		}

		int nMin = INT_MAX;

		for (int i = 0; i < nSize; ++i) {
			if (pArray[i] < nMin)
				nMin = pArray[i];
		}

		delete[] pArray;
		pArray = nullptr;

		cout << nMin << endl;
	}
	return 0;
}