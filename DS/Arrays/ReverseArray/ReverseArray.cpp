#include <iostream>
using namespace std;

int main(int argc, char** pArgv) {
	size_t nNumberOfInputs;
	cin >> nNumberOfInputs;

	while (nNumberOfInputs--) {
		int nSize;
		cin >> nSize;

		int* pArray = new int[nSize];
		for (int i = 0; i < nSize; ++i) {
			cin >> pArray[i];
		}

		for (int i = nSize - 1; i >= 0; --i) {
			cout << pArray[i] << " ";
		}

		delete[] pArray;
		pArray = nullptr;

		cout << endl;
	}

	return 0;
}