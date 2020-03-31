#include <iostream>

using namespace std;

//As we know, Ishaan has a love for chocolates.He has bought a huge chocolate 
//bar which contains N chocolate squares. Each of the square has a tastiness 
//level which is denoted by an array A[]. Ishaan can eat the first or the last 
//square of the chocolate at once. Ishaan has a sister who loves chocolates too
//and she demands the last chocolate square. Now, Ishaan being greedy eats the 
//more tasty square first. Determine the tastiness level of the square which 
//his sister gets.
int main() {
	//The first line in the input contains the number of test cases
	int nNumberOfTestCases;
	cin >> nNumberOfTestCases;

	while (nNumberOfTestCases-- > 0) {
		//The next line contains space separated size of the array
		size_t nSize;
		cin >> nSize;
		//Now read the array data
		int* pArray = new int[nSize];
		for (size_t i = 0; i < nSize; ++i) {
			cin >> pArray[i];
		}

		int nBegin(0), nEnd(nSize - 1), nRemaining(nSize);

		while (nRemaining != 1) {
			if (pArray[nBegin] > pArray[nEnd]) {
				nBegin++;
			}
			else
				nEnd--;

			nRemaining++;
		}

		cout << ((nBegin < nEnd) ? pArray[nEnd] : pArray[nBegin]) << endl;
		delete[] pArray;
		pArray = nullptr;
	}
	return 0;
}