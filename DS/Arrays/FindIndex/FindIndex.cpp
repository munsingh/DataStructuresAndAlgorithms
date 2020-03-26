#include <iostream>

using namespace std;

//Given an unsorted array Arr[] of N integers and a Key which is present in 
//this array. You need to write a program to find the start index
//(index where the element is first found from left in the array) and end 
//index (index where the element is first found from right in the array).
int main(int nArgc, char** pArgv) {
	//The first line in the input contains the number of test cases
	int nNumberOfTestCases;
	cin >> nNumberOfTestCases;

	while (nNumberOfTestCases-- > 0) {
		//The next line contains the size of the array
		int nSize, nElement;
		cin >> nSize;

		//Now read the array data
		int* pArray = new int[nSize];
		for (size_t i = 0; i < nSize; ++i) {
			cin >> pArray[i];
		}

		cin >> nElement;

		//iterate the array
		int nLeftIndex(0);
		for (int i = 0; i < nSize; ++i) {
			if (pArray[i] == nElement) {
				nLeftIndex = i;
				break;
			}
		}

		int nEndIndex(0);
		for (int i = nSize - 1; i > 0; --i) {
			if (pArray[i] == nElement) {
				nEndIndex = i;
				break;
			}
		}

		cout << nLeftIndex << " " << nEndIndex << endl;
		delete[] pArray;
		pArray = nullptr;
	}
	return 0;
}