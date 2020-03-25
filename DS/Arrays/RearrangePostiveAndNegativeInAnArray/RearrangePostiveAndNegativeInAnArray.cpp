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
		for (int i = 0; i < nSize; ++i) {
			cin >> pArray[i];
		}

		//Rearrange positive and negative in such a way that all negtive
		//numbers are on the left and positive numbers are on the right
		for (int j = 0, i = -1; j < nSize; ++j) {
			if (pArray[j] < 0) {
				std::swap(pArray[++i], pArray[j]);
			}
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