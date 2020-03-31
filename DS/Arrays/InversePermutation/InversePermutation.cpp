#include <iostream>
using namespace std;

//Given an array A of size n of integers in the range from 1 to n, we need to 
//find the inverse permutation of that array. Inverse Permutation is a 
//permutation which you will get by inserting position of an element at the 
//position specified by the element value in the array. For better 
//understanding, consider the following example :
//Suppose we found element 4 at position 3 in an array, then in reverse 
//permutation, we insert 3 (position of element 4 in the array) in position 4 
//(element value).

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

		
		for (size_t i = 0; i < nSize; ++i) {
			cout << pArray[i] << " ";
		}
		cout << endl;

		delete[] pArray;
		pArray = nullptr;
	}
	return 0;
}