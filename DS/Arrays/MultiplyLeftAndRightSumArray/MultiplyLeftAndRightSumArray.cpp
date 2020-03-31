#include <iostream>
using namespace std;

//Pitsy needs help in the given task by her teacher. The task is to divide an
//array into two sub array (left and right) containing n/2 elements each and 
//do the sum of the subarrays and then multiply both the subarrays.
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

		
		int nSumLeft(0), nSumRight(0);
		for (int i = 0; i < nSize / 2; ++i) {
			nSumLeft += pArray[i];
		}

		for (int i = nSize / 2; i < nSize; ++i) {
			nSumRight += pArray[i];
		}

		cout << nSumLeft * nSumRight << endl;

		delete[] pArray;
		pArray = nullptr;
	}
	return 0;
}