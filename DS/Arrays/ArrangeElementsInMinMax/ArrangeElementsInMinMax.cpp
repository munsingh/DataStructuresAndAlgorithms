#include <iostream>

using namespace std;

//Given an unsorted array arr of size N, rearrange the elements of array such 
//that number at the odd index is greater than the number at the previous even 
//index.
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

		//iterate the array
		for (int i = 1; i < nSize; i += 2) {
			//elements at odd indices
			if (pArray[i] < pArray[i - 1]) {
				swap(pArray[i], pArray[i - 1]);
			}
		}

		for (int i = 0; i < nSize; ++i) {
			cout << pArray[i] << " ";
		}

		cout << endl;
		delete[] pArray;
	}

	return 0;
}