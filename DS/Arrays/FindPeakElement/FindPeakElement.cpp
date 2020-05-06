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
		int* pArray = new int[nSize];
		for (int64_t i = 0; i < nSize; ++i) {
			cin >> pArray[i];
		}


		delete[] pArray;
		pArray = nullptr;
	}

	return 0;
}