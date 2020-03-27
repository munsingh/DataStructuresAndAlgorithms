#include <iostream>

using namespace std;

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

		bool bIsPalindrome = true;
		int nLeft(0), nRight(nSize - 1);
		while( nLeft <= nRight) {
			if (pArray[nLeft++] != pArray[nRight--]){
				bIsPalindrome = false;
				break;
			}
		}

		cout << (bIsPalindrome ? "PERFECT" : "NOT PERFECT") << endl;
		delete[] pArray;
		pArray = nullptr;
	}
	return 0;
}