#include <iostream>
#include <sstream>

using namespace std;

int main(int nArgc, char** pArgv) {
	//The first line in the input contains the number of test cases
	int nNumberOfTestCases;
	cin >> nNumberOfTestCases;

	while (nNumberOfTestCases-- > 0) {
		//The next line contains the size of the array
		size_t nSize;
		cin >> nSize;

		//Now read the array data
		int* pArray = new int[nSize];
		for (size_t i = 0; i < nSize; ++i) {
			cin >> pArray[i];
		}

		//find out if the array contents elements which are palindrome
		//if all elements are palindrome then return 1 else return 0
		//Since we have an integer array, so each element is an integer
		//We need to split the element and put its contents in another array
		//and then iterate the array from begining and end and break
		//the moment they do not match
		//So to split the contents
		//we first divide the number by 10, then 100, 1000 till the result
		//goes below zero.
		//So if the number is 12234, which needs to be split
		//then first take the modulas of the number by 10
		//Result is the first number
		//Subtract the result from the number, then divide it by 10
		//then repeat till the subtraction result does not become 0
		stringstream ss;
		string strNumber;
		bool bIsPalindrome(true);

		for (int i = 0; i < nSize; ++i) {
			ss << pArray[i];
			strNumber = ss.str();
			size_t nBegin(0), nLast(strNumber.size()-1);

			while (nBegin < nLast) {
				if (strNumber[nBegin++] != strNumber[nLast--]) {
					bIsPalindrome = false;
					break;
				}
			}

			if (!bIsPalindrome) {
				cout << 0 << endl;
				break;
			}

			ss.clear();
			ss.str("");
		}

		if (bIsPalindrome) {
			cout << 1 << endl;
		}

		delete[] pArray;
		pArray = nullptr;
	}

	return 0;
}