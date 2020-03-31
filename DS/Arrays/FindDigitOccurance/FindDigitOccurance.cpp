#include <iostream>
#include <sstream>
#include <string>

using namespace std;

//Given an array A[]  of n elements. Your task is to complete the Function num 
//which returns an integer denoting the total number of times digit k appears 
//in the whole array.
//
//For Example :
//
//A[] = { 11,12,13,14,15 }, k = 1
//
//Output = 6 //Count of the digit 1 in the array
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

		int nDigitToSearch(0);
		cin >> nDigitToSearch;

		//Iterate the array, split each number to its individual digits
		//and check if the digit is the digit we are looking for
		//If it is then increment the count by 1
		//Once done with the number, move to the next number, till the end of
		//the array
		int nCount(0);
		stringstream ss;
		string strNumber;
		size_t nNumberSize(0);
		for (int i = 0; i < nSize; ++i) {
			ss << pArray[i];
			strNumber = ss.str();
			nNumberSize = strNumber.size();

			for (size_t j = 0; j < nNumberSize; ++j) {
				if (static_cast<int>(strNumber[j]) - static_cast<int>('0') == 
					nDigitToSearch) {
					++nCount;
				}
			}

			ss.clear();
			ss.str("");
		}
		
		cout << nCount << endl;

		delete[] pArray;
		pArray = nullptr;
	}
	return 0;
}