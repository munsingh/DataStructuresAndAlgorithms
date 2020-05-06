#include <iostream>
using namespace std;

//An array is called Bitonic if it is comprises of an increasing sequence of 
//integers followed immediately by a decreasing sequence of integers.
//Given a bitonic array A of N distinct integers. Find a element X in it.
int main(int nArgc, char** pArgv) {
	//The first line in the input contains the number of test cases
	int nNumberOfTestCases;
	cin >> nNumberOfTestCases;

	while (nNumberOfTestCases-- > 0) {
		//The next line contains the size of the array and the number
		//to whicht he closest value has to be found
		int64_t nSize;
		cin >> nSize;

		//Now read the array data
		int* pArray = new int[nSize];
		for (int64_t i = 0; i < nSize; ++i) {
			cin >> pArray[i];
		}

		int nElement;
		cin >> nElement;
		//To find the bitonic point we will use method similar to binary search
		int nLeft = 0, nRight = nSize - 1;
		int nMid = (nLeft + nRight) / 2;

		while (nLeft <= nRight) {
			if (pArray[nMid] > pArray[nMid - 1]) {
				nLeft = nMid;

			}
			else if( pArray[nMid] < pArray[])
		}

		delete[] pArray;
		pArray = nullptr;
	}

	return 0;
}