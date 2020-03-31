#include <iostream>
using namespace std;

int main(int argc, char** pArgv) {
	size_t nNumberOfInputs;
	cin >> nNumberOfInputs;

	while (nNumberOfInputs--) {
		int nSize, nNumberToSearch;
		cin >> nSize >> nNumberToSearch;

		int* pArray = new int[nSize];
		for (int i = 0; i < nSize; ++i) {
			cin >> pArray[i];
		}
		
		int nCount(0);
		for (int i = 0; i < nSize; ++i) {
			if (pArray[i] == nNumberToSearch) {
				nCount++;
			}
		}

		cout << (nCount == 0 ? -1 : nCount ) << endl;
		delete[] pArray;
		pArray = nullptr;
	}

	return 0;
}