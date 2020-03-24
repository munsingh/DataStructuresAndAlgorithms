#include <iostream>

using namespace std;

//Implement an algorithm function, which takes an array and returns an array so
//that each index has a product of all the numbers present in the array except 
//the number stored at that index.
int main(int nArgc, char** pArgv) {
	//The first line in the input contains the number of test cases
	int nNumberOfTestCases;
	cin >> nNumberOfTestCases;


	while (nNumberOfTestCases-- > 0) {
		//The next line contains the size of the array
		int nSize;
		cin >> nSize;

		//Now read the array data
		int* pArray = new int[nSize];
		for (size_t i = 0; i < nSize; ++i) {
			cin >> pArray[i];
		}

		//so for this we will find the product of the numbers left to it
		//and then the product of the numbers right to it
		//and then multiply these two and store it at that index
		int* pProductArray = new int[nSize];
		int nTemp = 1;
		for (int i = 0; i < nSize; ++i) {
			*(pProductArray + i) = nTemp;
			nTemp *= *(pArray + i);
		}

		nTemp = 1;
		for (int i = nSize - 1; i >= 0; --i) {
			*(pProductArray + i) *= nTemp;
			nTemp *= *(pArray + i);
		}

		for (int i = 0; i < nSize; ++i) {
			cout << *(pProductArray + i) << " ";
		}

		delete[] pProductArray;
		pProductArray = nullptr;
		delete[] pArray;
		pArray = nullptr;

		cout << endl;
	}
	return 0;
}