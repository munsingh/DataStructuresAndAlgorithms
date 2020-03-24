#include <iostream>

using namespace std;

int main(int nArgc, char** pArgv) {
	size_t nNumberOfInputs(0);
	cin >> nNumberOfInputs;

	while (nNumberOfInputs--) {
		int nSize1(0), nSize2(0);
		cin >> nSize1 >> nSize2;

		int* pArray1 = new int[nSize1];
		for (int i = 0; i < nSize1; ++i) {
			cin >> pArray1[i];
		}

		int* pArray2 = new int[nSize2];
		for (int i = 0; i < nSize2; ++i) {
			cin >> pArray2[i];
		}

		//The merged array will be the sum of the existing arrays
		int nMergedArraySize = nSize1 + nSize2;
		int* pMergedArray = new int[nMergedArraySize];

		//To merge two sorted arrays
		//We need to compare the values from the two arrays and keep adding
		//the smaller one first into the merged array
		//While doing this we need to keep in mind that one of the arrays
		//may be smaller and run out.
		//Once we are done with the smaller array, copy the contents of the
		//remaining bigger array into the merged array
		int i = 0, j = 0, nMergedArrayIndex = 0;
		while (i < nSize1 && j < nSize2) {
			pMergedArray[nMergedArrayIndex++] =
				pArray1[i] < pArray2[j] ? pArray1[i++] : pArray2[j++];
		}

		//We ran out of iterating the smaller array
		//now we find which one we ran out and just copy the remaining contents of that to the
		//merged array
		if (i < nSize1 && j < nSize2) {
			//do nothing we are done
			;
		}
		else {
			//one of the two ran out
			//check which one
			if (j < nSize2) {
				//that means we are done iterating the 1st array
				//so copy the remaining contents of the 2nd array
				for (; j < nSize2; ++j) {
					pMergedArray[nMergedArrayIndex++] = pArray2[j];
				}
			}
			else if (i < nSize1) {
				//that means we are done iterating the 2nd array
				//so copy the remaining contents of the 1st array
				for (; i < nSize1; ++i) {
					pMergedArray[nMergedArrayIndex++] = pArray1[i];
				}
			}
			else {
				//should not come here
			}
		}

		for (int i = 0; i < nMergedArraySize; ++i) {
			cout << pMergedArray[i] << " ";
		}

		delete[] pMergedArray;
		pMergedArray = nullptr;

		delete[] pArray1;
		pArray1 = nullptr;

		delete[] pArray2;
		pArray2 = nullptr;

		cout << endl;
	}

	return 0;
}