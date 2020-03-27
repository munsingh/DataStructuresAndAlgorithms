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

		bool bFound = false;
		for (int i = 0; i < nSize; ++i) {
			if (pArray[i] == (i + 1)) {
				cout << pArray[i] << " ";
				bFound = true;
			}
		}

		if (!bFound) {
			cout << "Not Found" << endl;
		}
		else
			cout << endl;

		delete[] pArray;
		pArray = nullptr;
	}
	return 0;
}