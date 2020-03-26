#include <iostream>
#include <algorithm>
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

		//without sorting approach is below
		/*int nMax = INT_MIN;

		for (int i = 0; i < nSize; ++i) {
			if (pArray[i] > nMax) {
				nMax = pArray[i];
			}
		}

		int n2ndMax = INT_MIN;
		for (int i = 0; i < nSize; ++i) {
			if (pArray[i] > n2ndMax && pArray[i] < nMax) {
				n2ndMax = pArray[i];
			}
		}

		for (int i = 0; i < nSize; ++i) {
			if (pArray[i] != nMax && pArray[i] != n2ndMax) {
				cout << pArray[i] << " ";
			}
		}*/

		std::sort(pArray, pArray + nSize);
		for (int i = 0; i < nSize - 2; ++i) {
			cout << pArray[i] << " ";
		}

		cout << endl;
		delete[] pArray;
		pArray = nullptr;
	}
	return 0;
}