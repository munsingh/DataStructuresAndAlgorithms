#include <iostream>
using namespace std;

//Given a array a[] of non-negative integers. Count the number of pairs (i, j) 
//in the array such that a[i] + a[j] < a[i]*a[j]. 
//(the pair (i, j) and (j, i) are considered same and i should not be equal 
//to j)
int main(int argc, char** pArgv) {
	size_t nNumberOfInputs;
	cin >> nNumberOfInputs;

	while (nNumberOfInputs--) {
		int64_t nSize;
		cin >> nSize;

		int* pArray = new int[nSize];
		for (int64_t i = 0; i < nSize; ++i) {
			cin >> pArray[i];
		}

		int nCount(0);
		for (int64_t i = 0; i < nSize; ++i) {
			for (int64_t j = i + 1; j < nSize; ++j) {
				if (pArray[i] + pArray[j] < pArray[i] * pArray[j]) {
					++nCount;
				}
			}
		}

		delete[] pArray;
		pArray = nullptr;

		cout << nCount << endl;
	}

	return 0;
}