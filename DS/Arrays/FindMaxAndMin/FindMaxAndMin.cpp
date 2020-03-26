#include <iostream>

using namespace std;

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

		int nMin(INT_MAX), nMax(INT_MIN);

		for (int64_t i = 0; i < nSize; ++i) {
			if (pArray[i] > nMax)
				nMax = pArray[i];

			if (pArray[i] < nMin) {
				nMin = pArray[i];
			}
		}

		cout << nMax << " " << nMin << endl;
	}
	return 0;
}