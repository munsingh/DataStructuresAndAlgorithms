#include <iostream>
#include <string>

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
		string* pArray = new string[nSize];
		for (size_t i = 0; i < nSize; ++i) {
			cin >> pArray[i];
		}

		size_t nMax(0), nMaxIndex(0);
		for (int i = 0; i < nSize; ++i) {
			if (pArray[i].size() > nMax) {
				nMax = pArray[i].size();
				nMaxIndex = i;
			}
		}

		cout << pArray[nMaxIndex] << endl;

		delete[] pArray;
		pArray = nullptr;
	}
	return 0;
}