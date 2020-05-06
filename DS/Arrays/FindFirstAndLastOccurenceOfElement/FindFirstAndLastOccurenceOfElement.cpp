#include <iostream>
using namespace std;

//Given a sorted array with possibly duplicate elements. The task is to find 
//indexes of first and last occurrences of an element X in the given array.
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

		bool bFoundFirst = false, bFoundLast = false;
		int64_t nFirstOccurence, nLastOccurence;

		for (int64_t i = 0; i < nSize; ++i) {
			if (nElement == pArray[i]) {
				nFirstOccurence = i;
				bFoundFirst = true;
				break;
			}
		}

		for (int64_t i = nSize -1 ; i >= 0; --i) {
			if (nElement == pArray[i]) {
				nLastOccurence = i;
				bFoundLast = true;
				break;
			}
		}
		
		delete[] pArray;
		pArray = nullptr;

		if (bFoundFirst && bFoundLast)
			cout << nFirstOccurence << " " << nLastOccurence;
		else
			cout << -1;

		cout << endl;
	}

	return 0;
}