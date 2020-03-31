#include <iostream>
#include <sstream>
#include <string>

using namespace std;

//You are given an array A of size N. Replace every element with the next 
//greatest element (greatest element on its right side) in the array. Also,
//since there is no element next to the last element, replace it with -1.
int main() {
	//The first line in the input contains the number of test cases
	int nNumberOfTestCases;
	cin >> nNumberOfTestCases;

	while (nNumberOfTestCases-- > 0) {
		//The next line contains the number where 0s have to be replaced with 5
		size_t nNumber;
		cin >> nNumber;

		stringstream sStream;
		sStream << nNumber;
		string strNumber = sStream.str();
		size_t nSize = strNumber.size();
		for (size_t i = 0; i < nSize; ++i) {
			if (strNumber[i] == '0') {
				strNumber[i] = '5';
			}
		}

		cout << atoi( strNumber.c_str() ) << endl;
	}
	return 0;
}