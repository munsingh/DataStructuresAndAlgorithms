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

		//First find the max in the array
		int nMax = INT_MIN;
		int n2ndMax = INT_MIN;

		for (int i = 0; i < nSize; ++i) {
			if (pArray[i] > nMax) {
				n2ndMax = nMax;
				nMax = pArray[i];
			}
			else if (pArray[i] > n2ndMax) {
				n2ndMax = pArray[i];
			}
			else {
				;//do nothing
			}
		}

		cout << n2ndMax << endl;
		delete[] pArray;
		pArray = nullptr;
	}

	return 0;
}