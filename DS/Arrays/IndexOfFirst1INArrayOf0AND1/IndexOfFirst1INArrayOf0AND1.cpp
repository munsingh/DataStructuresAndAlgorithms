#include <iostream>

using namespace std;

//CodeMart is an online shopping platform and it is distributing gift vouchers 
//to its esteemed users.The voucher can be redeemed by providing a fixed amount
//of shopping credits. Each credit is sent by a user one by one. Since there is
//a huge rush of people you are required to manage the users on the basis of 
//first come first serve. The user which comes first and has k occurrences of 
//credits is given the voucher first. You are given an array with the id's of 
//the users in chronological order of the credits sent by them. 
//You are required to print the id of the user which will be served first. 
//If no such user meets the condition print "-1".
int main(int nArgc, char** pArgv) {
	//The first line in the input contains the number of test cases
	int nNumberOfTestCases;
	cin >> nNumberOfTestCases;

	while (nNumberOfTestCases-- > 0) {
		//The next line contains the size of the array
		int64_t nSize;
		cin >> nSize;

		//Now read the array data
		int* pArray = new int[nSize];
		for (int i = 0; i < nSize; ++i) {
			cin >> pArray[i];
		}

		bool bFound = false;
		for (int64_t i = 0; i < nSize; ++i) {
			if (pArray[i] == 1) {
				cout << i << endl;
				bFound = true;
			}
		}

		if (!bFound) {
			cout << -1 << endl;
		}
		delete[] pArray;
		pArray = nullptr;
	}

	return 0;
}