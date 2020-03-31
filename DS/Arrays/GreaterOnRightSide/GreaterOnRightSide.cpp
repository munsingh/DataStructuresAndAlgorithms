#include <iostream>
using namespace std;

//You are given an array A of size N. Replace every element with the next 
//greatest element (greatest element on its right side) in the array. Also,
//since there is no element next to the last element, replace it with -1.
int main() {
	//The first line in the input contains the number of test cases
	int nNumberOfTestCases;
	cin >> nNumberOfTestCases;

	while (nNumberOfTestCases-- > 0) {
		//The next line contains space separated size of the array and rotation count
		size_t nSize;
		cin >> nSize;

		//Now read the array data
		int* pArray = new int[nSize];
		for (size_t i = 0; i < nSize; ++i) {
			cin >> pArray[i];
		}

		//for replacing element with the greatest element on its right
		//we start two loops
		int nMax = INT_MIN;
		for (int i = 0; i < nSize - 1; ++i) {
			//now find the greatest element on the right of parray[i]
			//i.e., from pArray[i+1]
			//the last element at the end becomes -1
			for (int j = i + 1; j < nSize; ++j) {
				if (pArray[j] > nMax) {
					nMax = pArray[j];
				}
			}
			pArray[i] = nMax;
			nMax = INT_MIN;
		}

		pArray[nSize - 1] = -1;

		for (size_t i = 0; i < nSize; ++i) {
			cout << pArray[i] << " ";
		}
		cout << endl;

		delete[] pArray;
		pArray = nullptr;
	}
	return 0;
}