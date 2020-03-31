#include <iostream>

using namespace std;

//Given an array A (distinct elements) of size N.Rearrange the elements of 
//array in zig - zag fashion. The converted array should be in form 
//a < b > c < d > e < f. The relative order of elements is same in the output 
//i.e you have to iterate on the original array only.
int main() {
	//The first line in the input contains the number of test cases
	int nNumberOfTestCases;
	cin >> nNumberOfTestCases;

	while (nNumberOfTestCases-- > 0) {
		//The next line contains space separated size of the array
		size_t nSize;
		cin >> nSize;

		//Now read the array data
		int* pArray = new int[nSize];
		for (size_t i = 0; i < nSize; ++i) {
			cin >> pArray[i];
		}

		for (int i = 0; i < nSize; ++i) {
			//for elements at even indices we check with next neighbour
			//and follow the rule a < b, otherwise swap it
			//for elements at odd indices we check with next neighbour
			//and follow the rule b > c.
			//first check whether odd index or even
			if (i + 1 == nSize) {
				continue;
			}

			if (i % 2 == 0) {
				//even index
				if (pArray[i] > pArray[i + 1]) {
					//swap them
					swap(pArray[i], pArray[i + 1]);
				}
				else {
					;//do nothing. Already in the correct order
				}
			}
			else {
				//odd index
				if (pArray[i] < pArray[i + 1]) {
					//swap them
					swap(pArray[i], pArray[i + 1]);
				}
				else {
					;//do nothing. Already in the correct order
				}
			}
		}

		for (int i = 0; i < nSize; ++i) {
			cout << pArray[i] << " ";
		}

		cout << endl;
		delete[] pArray;
		pArray = nullptr;
	}
	return 0;
}