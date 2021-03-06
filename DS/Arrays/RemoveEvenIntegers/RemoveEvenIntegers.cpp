#include <iostream>

using namespace std;

int main(int argc, char** pArgv) {
	size_t nNumberOfInputs(0);
	cin >> nNumberOfInputs;

	while (nNumberOfInputs--) {
		int nSize(0);
		cin >> nSize;

		int* pArray = new int[nSize];
		for (int i = 0; i < nSize; ++i) {
			cin >> pArray[i];
		}

		int j = 0;
		for (int i = 0; i < nSize; ++i) {
			if (pArray[i] % 2 != 0) {
				//odd, so insert it
				pArray[j++] = pArray[i];
			}
		}

		pArray[j] = '\0';

		for (int i = 0; i < j; ++i) {
			cout << pArray[i] << " ";
		}

		delete[] pArray;
		pArray = nullptr;

		cout << endl;
	}

	return 0;
}