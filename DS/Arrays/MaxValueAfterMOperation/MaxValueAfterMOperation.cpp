#include <iostream>
using namespace std;

//Given an array of size N with all initial values as 0, write a program to 
//perform following M range increment operations as shown below:
//	increment(a, b, k) : Increment values from 'a' to 'b' by 'k'.
//
//	After M operations, calculate the maximum value in the array.
int main() {
	//The first line in the input contains the number of test cases
	int nNumberOfTestCases;
	cin >> nNumberOfTestCases;


	while (nNumberOfTestCases-- > 0) {
		//The next line contains space separated size of the array and rotation count
		size_t nSize, nRotationCount;
		cin >> nSize >> nRotationCount;
		//Now read the array data
		int* pArray = new int[nSize];
		for (size_t i = 0; i < nSize; ++i) {
			cin >> pArray[i];
		}

		
		cout << endl;

		delete[] pArray;
		pArray = nullptr;
	}
	return 0;
}