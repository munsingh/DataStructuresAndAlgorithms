#include <iostream>
#include <limits.h>
using namespace std;

//Given an array with all elements greater than or equal to zero. Return the 
//maximum product of two numbers possible.
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

		int64_t nMax(INT_FAST64_MIN), n2ndMax(INT_FAST64_MIN);
		for (int i = 0; i < nSize; ++i) {
			if (pArray[i] > nMax) {
				n2ndMax = nMax;
				nMax = pArray[i];
			}
			else if (pArray[i] > n2ndMax) {
				n2ndMax = pArray[i];
			}
			else {
				;//do nothing
			}
		}
		
		int64_t nProduct = nMax * n2ndMax;

		delete[] pArray;
		pArray = nullptr;

		cout << nProduct << endl;
	}

	return 0;
}