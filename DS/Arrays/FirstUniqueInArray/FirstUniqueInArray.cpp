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

		//Simple Approach is brute method in O(n^2).
		bool bUnique = true;

		for (int i = 0; i < nSize; ++i) {
			for (int j = 0; j < nSize; ++j) {
				if (pArray[i] == pArray[j] && i != j) {
					bUnique = false;
				}
			}

			if (bUnique) {
				cout << pArray[i] << endl;
				break;
			}

			//reset the flag
			bUnique = true;
		}

		delete[] pArray;
		pArray = nullptr;
	}
	return 0;
}