#include <iostream>

using namespace std;

int main(int argc, char** pArgv) {
	size_t nNumberOfInputs(0);
	cin >> nNumberOfInputs;

	while (nNumberOfInputs--) {
		int nSize(0), nSubArraySize(0);
		cin >> nSize >> nSubArraySize;

		int* pArray = new int[nSize];
		for (int i = 0; i < nSize; ++i) {
			cin >> pArray[i];
		}

		

		delete[] pArray;
		pArray = nullptr;

		cout << endl;
	}

	return 0;
}