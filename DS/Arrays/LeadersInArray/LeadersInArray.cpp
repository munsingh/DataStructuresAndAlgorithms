#include <iostream>
#include <vector>

using namespace std;

//Given an array of positive integers.Your task is to find the leaders in the array.
//Note: An element of array is leader if it is greater than or equal to all the elements to its right side.Also, the rightmost element is always a leader.
//
//	Input :
//	The first line of input contains an integer T denoting the number of test cases.The description of T test cases follows.
//	The first line of each test case contains a single integer N denoting the size of array.
//	The second line contains N space - separated integers A1, A2, ..., AN denoting the elements of the array.
//
//	Output:
//		Print all the leaders.
//
//			Constraints :
//			1 <= T <= 100
//			1 <= N <= 107
//			0 <= Ai <= 107
//
//			Example :
//			Input :
//			3
//			6
//			16 17 4 3 5 2
//			5
//			1 2 3 4 0
//			5
//			7 4 5 7 3
//			Output:
//		17 5 2
//			4 0
//			7 7 3
//
//			Explanation :
//			Testcase 3 : All elements on the right of 7 (at index 0) are smaller than or equal to 7. 
//			Also, all the elements of right side of 7 (at index 3) are smaller than 7. 
//			And, the last element 3 is itself a leader since no elements are on its right.
int main(int argc, char** pArgv) {
	size_t nNumberOfInputs;
	cin >> nNumberOfInputs;

	while (nNumberOfInputs--) {
		int nSize;
		cin >> nSize;

		int* pArray = new int[nSize];
		for (int i = 0; i < nSize; ++i) {
			cin >> pArray[i];
		}

		//working but un-optmized algorithm
		/*bool bGreater = true;
		for (size_t i = 0; i < nSize; ++i) {
			for (size_t j = i + 1; j < nSize; ++j) {
				if (pArray[i] < pArray[j]) {
					bGreater = false;
					break;
				}
			}

			if (bGreater)
				cout << pArray[i] << " ";

			bGreater = true;
		}*/

		//Optimized O(n) algorithm
		//Scan from right to left
		int nMax = pArray[nSize - 1];
		int* pDisplayArray = new int[nSize];
		int nDisplayCounter = nSize - 1;

		pDisplayArray[nDisplayCounter--] = nMax;

		for (int i = nSize - 2; i >= 0; --i) {
			if (nMax <= pArray[i]) {
				nMax = pArray[i];
				//oMax.insert(oMax.begin(), nMax);
				pDisplayArray[nDisplayCounter--] = nMax;
			}
		}

		//print the contents of stringstream in reverse.
		for (int i = nDisplayCounter + 1; i <= nSize - 1; ++i) {
			cout << pDisplayArray[i] << " ";
		}

		cout << endl;
		delete[] pDisplayArray;
		delete[] pArray;
	}

	return 0;
}