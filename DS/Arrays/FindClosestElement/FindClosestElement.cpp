#include <iostream>

using namespace std;

//Given an array of sorted integers. The task is to find the closest value to 
//the given number in array. Array may contain duplicate values.
//
//Note: If the difference is same for two values print the value which is 
//greater than the given number.
int main(int nArgc, char** pArgv) {
	//The first line in the input contains the number of test cases
	int nNumberOfTestCases;
	cin >> nNumberOfTestCases;

	while (nNumberOfTestCases-- > 0) {
		//The next line contains the size of the array and the number
		//to whicht he closest value has to be found
		int64_t nSize;
		cin >> nSize;

		int nNumber;
		cin >> nNumber;

		//Now read the array data
		int* pArray = new int[nSize];
		for (int64_t i = 0; i < nSize; ++i) {
			cin >> pArray[i];
		}

		int nClosest = INT_MAX;
		int64_t nClosesetIndex = -1, nPrevClosesetIndex = -1;
		for (int64_t i = 0; i < nSize; ++i) {
			if (abs(nNumber - pArray[i]) <= nClosest) {
				nClosest = abs(nNumber - pArray[i]);
				nPrevClosesetIndex = nClosesetIndex;
				nClosesetIndex = i;
				if (i > 0 && (abs(nNumber - pArray[nClosesetIndex]) ==
					abs(nNumber - pArray[nPrevClosesetIndex]))) {
					//both deltas are same, so the closese index is the one
					//which is greater than the number
					if (nNumber > pArray[nClosesetIndex]) {
						nPrevClosesetIndex = nClosesetIndex;
						nClosesetIndex = nClosesetIndex;
					}
					else if (nNumber > pArray[nPrevClosesetIndex]) {
						nPrevClosesetIndex = nClosesetIndex;
						nClosesetIndex = nPrevClosesetIndex;
					}
					else {
						//they are equal
						nClosesetIndex = nClosesetIndex;
					}
				}
			}
		}


		cout << pArray[nClosesetIndex] << endl;
		delete[] pArray;
		pArray = nullptr;
	}

	return 0;
}