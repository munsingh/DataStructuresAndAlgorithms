#include <iostream>

using namespace std;

int main(int nArgc, char** pArgv) {
	//The first line in the input contains the number of test cases
	int nNumberOfTestCases;
	cin >> nNumberOfTestCases;

	while (nNumberOfTestCases-- > 0) {
		//The next line contains the size of the array
		int nSize, nElement;
		cin >> nSize >> nElement;

		//Now read the array data
		int* pArray = new int[nSize];
		for (size_t i = 0; i < nSize; ++i) {
			cin >> pArray[i];
		}

		int64_t nLessCount(0), nMoreCount(0);
		
		for (int i = 0; i < nSize; ++i) {
			if (pArray[i] <= nElement) {
				nLessCount++;
			}
			
			if (pArray[i] >= nElement) {
				nMoreCount++;
			}
		}

		cout << nLessCount << " " << nMoreCount << endl;
		delete[] pArray;
		pArray = nullptr;
	}
	return 0;
}