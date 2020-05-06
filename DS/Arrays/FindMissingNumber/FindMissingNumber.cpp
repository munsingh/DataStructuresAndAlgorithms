#include <iostream>
using namespace std;

//Given an array A of N integers. The task is to find a peak element in it in 
//O( log N ). An array element is peak if it is not smaller than its 
//neighbours. For corner elements, we need to consider only one neighbour.
//Note: There may be multiple peak element possible, in that case you may 
//return any valid index.
int main(int nArgc, char** pArgv) {
	//The first line in the input contains the number of test cases
	int nNumberOfTestCases;
	cin >> nNumberOfTestCases;

	while (nNumberOfTestCases-- > 0) {
		//The next line contains the size of the array and the number
		//to whicht he closest value has to be found
		int64_t nSize;
		cin >> nSize;

		//Now read the array data
		int nSum1(0);
		for (int64_t i = 0; i < nSize; ++i) {
			nSum1 += (i+1);
		}

		int nSum2(0), nNumber;
		//Now read the array data
		for (int64_t i = 0; i < nSize -1 ; ++i) {
			cin >> nNumber;
			nSum2 += nNumber;
		}

		cout << nSum1 - nSum2 << endl;
	}

	return 0;
}