#include <iostream>
using namespace std;

//Given a sorted array having 10 elements which contains 6 different numbers 
//in which only 1 number is repeated five times. Your task is to find the 
//duplicate number using two comparisons only.
int main(int nArgc, char** pArgv) {
	//The first line in the input contains the number of test cases
	int nNumberOfTestCases;
	cin >> nNumberOfTestCases;

	while (nNumberOfTestCases-- > 0) {
		//The next line contains the size of the array and the number
		//to whicht he closest value has to be found
		int64_t nSize(10);
		
		//Now read the array data
		int* pArray = new int[nSize];
		for (int64_t i = 0; i < nSize; ++i) {
			cin >> pArray[i];
		}

		//Since the array is sorted and contains 10 elements only and 
		//1 number is repeated 5 times
		//this means that the 5 repeated element will definitely cover
		//the center point even in worst case when the duplictes start 
		//from 0th index or start at 5th index
		//so we just need t compare the mid element with the left or right
		//and it is same then this is the element
		int nMid = nSize / 2;
		if (pArray[nMid] == pArray[nMid + 1])
			cout << pArray[nMid];
		else
			cout << pArray[nMid - 1];

		cout << endl;
		delete[] pArray;
		pArray = nullptr;
	}

	return 0;
}