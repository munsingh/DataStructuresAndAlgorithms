#include <iostream>
using namespace std;

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

		//We have the contents in the array
		//to rorate clockwise, i.e., left by nRotationCount
		//we iterate the array from begining.
		//We create a temporary array for storing the temporary values
		int* pTempArray = new int[nRotationCount];
		for (size_t i = 0; i < nRotationCount; ++i) {
			//store the elements in the temp array
			pTempArray[i] = pArray[i];
		}

		size_t i = 0;
		while (nRotationCount + i < nSize) {
			pArray[i] = pArray[nRotationCount + i++];
		}

		for (size_t i = nSize - nRotationCount, j = 0; i < nSize; i++, j++) {
			pArray[i] = pTempArray[j];
		}

		delete[] pTempArray;
		pTempArray = nullptr;

		for (size_t i = 0; i < nSize; ++i) {
			cout << pArray[i] << " ";
		}
		cout << endl;

		delete[] pArray;
		pArray = nullptr;
	}
	return 0;
}