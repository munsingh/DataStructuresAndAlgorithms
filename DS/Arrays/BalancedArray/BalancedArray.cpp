#include <iostream>
#include <stdlib.h>
using namespace std;

//Given an array of even size, task is to find minimum value that can be added
//to an element so that array become balanced. An array is balanced if the sum
//of the left half of the array elements is equal to the sum of right half. 
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

		//Calculate the same of left and the right half of the array
		//The delta between them is the minimum that needs to be added to the
		//smaller sum
		int nBegin(0), nEnd(nSize - 1), nLeftSum(0), nRightSum(0);

		while (nBegin <= nEnd) {
			nLeftSum += pArray[nBegin++];
			nRightSum += pArray[nEnd--];
		}

		cout << abs( nRightSum - nLeftSum) << endl;
		delete[] pArray;
	}

	return 0;
}