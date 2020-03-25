#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int main(int nArgc, char** pArgv) {
	//The first line in the input contains the number of test cases
	int nNumberOfTestCases;
	cin >> nNumberOfTestCases;

	while (nNumberOfTestCases-- > 0) {
		//The next line contains the size of the array
		int nSize;
		cin >> nSize;

		//Now read the array data
		int* pArray = new int[nSize];
		for (int i = 0; i < nSize; ++i) {
			cin >> pArray[i];
		}

		//to rearrange array in max min form in such a way that the maximum 
		//element appears at first, then minimum at second, then second maximum
		//at the third position, and second minimum at fourth and so on.

		//first we sort the array
		std::sort(pArray, pArray + nSize );

		//we create a temp array of the same size
		int* pTempArray = new int[nSize];

		//Now since the source array is sorted,
		//we take two pointers begining and end
		//we first take the end element put it in the first place
		//then take the begining and put it in the next place in the temp array
		//After each placement the begining counter increments by one and the
		//end counter decrements by one
		int nBegin(0), nEnd(nSize - 1);
		bool bFlag = true;
		for( int i = 0 ; i < nSize; ++i){
			pTempArray[i] = bFlag ? pArray[nEnd--] : pArray[nBegin++];
			bFlag = !bFlag;
		}
		
		
		int *pTemp = pArray;
		pArray = pTempArray;
		delete[] pTemp;
		pTemp = nullptr;

		//display the contents of the array
		for (int i = 0; i < nSize; ++i) {
			cout << pArray[i] << " ";
		}
		cout << endl;

		delete[] pArray;
		pArray = nullptr;
	}

	return 0;
}