#include <iostream>

using namespace std;

int main() {
	//The first line in the input contains the number of test cases
	int nNumberOfTestCases;
	cin >> nNumberOfTestCases;

	while (nNumberOfTestCases-- > 0) {
		//The next line contains space separated size of the array and rotation count
		size_t nSize, nRotationCount(1);
		cin >> nSize;

		bool bRotateLeft = false; //implies rotate right
		
		//Now read the array data
		int* pArray = new int[nSize];
		for (size_t i = 0; i < nSize; ++i) {
			cin >> pArray[i];
		}

		//To rotate an array left or right by n items
		//Let's take an example
		// 3 2 6 1 4 7 after rotating 2 items left will become
		// 6 1 4 7 3 2 i.e., the first two items were pushed out and appended
		// at the end
		// Same array if rotated 2 times right will become
		// 4 7 3 2 6 1 i.e., the last 2 items are pushed out and prepended

		//So first thing is we create 
		delete[] pArray;
		pArray = nullptr;
	}

	return 0;
}