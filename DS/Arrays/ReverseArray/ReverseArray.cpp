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

		//To reverse an array we need to start two pointers and swap them.
		//The two pointers will be front and last
		int nFirst(0), nLast(nSize - 1);

		while (true) {
			if (nFirst >= nLast)
				break;

			std::swap(pArray[nFirst++], pArray[nLast--]);
		}

		for (int i = 0; i < nSize; ++i) {
			cout << pArray[i] << " ";
		}

		delete[] pArray;
		pArray = nullptr;

		cout << endl;
	}

	return 0;
}