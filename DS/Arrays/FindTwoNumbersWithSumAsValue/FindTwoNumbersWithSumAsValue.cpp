#include <iostream>
#include <algorithm>

using namespace std;

int main(int nArgc, char** pArgv) {
	//The first line in the input contains the number of test cases
	int nNumberOfTestCases;
	cin >> nNumberOfTestCases;


	while (nNumberOfTestCases-- > 0) {
		//The next line contains space separated size of the array and rotation count
		int nSize, nValue;
		cin >> nSize >> nValue;

		//Now read the array data
		int* pArray = new int[nSize];
		for (size_t i = 0; i < nSize; ++i) {
			cin >> pArray[i];
		}

		//sort the array
		std::sort(pArray, pArray + nSize);

		//Now once this is sorted
		//For this we start from the begining and end
		//and keep checking whether the sum of these two numbers is equal to
		//the value
		//if it is less than the value then increment the start index
		//otherwise increment the last index
		int nStart = 0, nLast = nSize - 1, nSum(0);
		while (nStart != nLast) {
			nSum = pArray[nStart] + pArray[nLast];
			if (nSum < nValue)
				nStart++;
			else if (nSum > nValue)
				nLast--;
			else {
				//this is the value
				cout << pArray[nStart] << " " << pArray[nLast];
				break;
			}
		}

		cout << endl;
		delete[] pArray;
		pArray = nullptr;
	}
	
	return 0;
}