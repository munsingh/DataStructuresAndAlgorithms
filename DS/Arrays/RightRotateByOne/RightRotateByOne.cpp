#include <iostream>

using namespace std;

int main() {
	//The first line in the input contains the number of test cases
	int nNumberOfTestCases;
	cin >> nNumberOfTestCases;

	while (nNumberOfTestCases-- > 0) {
		//The next line contains space separated size of the array and rotation count
		int nSize, nRotationCount;
		bool bRotateLeft = false;
		cin >> nSize >> nRotationCount >> bRotateLeft;

		//Now read the array data
		int* pArray = new int[nSize];
		for (size_t i = 0; i < nSize; ++i) {
			cin >> pArray[i];
		}

		//To rotate an array left or right by n items
		//Let's take an example
		// 3 2 6 1 4 7 after rotating 2 items left (clockwise) will become
		// 6 1 4 7 3 2 i.e., the first two items were pushed out and appended
		// at the end
		// Same array if rotated 2 times right will become
		// 4 7 3 2 6 1 i.e., the last 2 items are pushed out and prepended

		//So first thing is we create a temp array, whose size is 
		//the number of items to be rotated
		//for frm 3 2 6 1 4 7 to be rotated left
		//we take out first two elements and store it in the temp array
		//if we are rotating right, then we take out the last 2 items 
		//and store it in the array
		int* pTempArray = new int[nRotationCount];

		//now fill up the pTempArray depending on the rotation direction
		//if left then 1st two entries, if right then last two entries
		for (int i = !bRotateLeft ? 0 : nSize - nRotationCount, j = 0;
				i < (!bRotateLeft ? nRotationCount : nSize);
				++i, ++j) {
			pTempArray[j] = pArray[i];
		}

		if (!bRotateLeft) {
			//now if we are rotating left then we start moving the contents of the
			//array from rotationcount position to the first position
			//will we have moved all elements from rotation count position
			int i = 0;
			while (nRotationCount + i < nSize) {
				pArray[i] = pArray[nRotationCount + i++];
			}

			//now we copy over the contents of pTempArray to ith position and
			//above
			for (int i = nSize - nRotationCount, j = 0; i < nSize; i++, j++) {
				pArray[i] = pTempArray[j];
			}
		}
		else {
			//we are rotating right so an array like 6 1 4 7 3 2 being rotated
			//right by 2 elements means we start at 0 and the element at that
			//place is copied to nRotationCount pos till we reach nRotationCount
			//-nSize -1 pos
			for (int i = nSize - 1; i >= nRotationCount; --i) {
				pArray[i] = pArray[i - nRotationCount];
			}

			for (int i = 0; i < nRotationCount; ++i) {
				pArray[i] = pTempArray[i];
			}
		}

		delete[] pTempArray;
		pTempArray = nullptr;

		for (int i = 0; i < nSize; ++i) {
			cout << pArray[i] << " ";
		}
		cout << endl;

		delete[] pArray;
		pArray = nullptr;
	}

	return 0;
}