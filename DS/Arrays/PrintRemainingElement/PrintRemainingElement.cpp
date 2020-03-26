#include <iostream>

using namespace std;

//Given a array of length N, at each step it is reduced by 1 element.
//In the first step the maximum element would be removed, while in the second 
//step minimum element of the remaining array would be removed, in the third 
//step again the maximum and so on. Continue this till the array contains only 
// 1 element. And print that final element remaining in the array.

int Partition(int *pArray, int nLeft, int nRight) {
	//Get the pivot
	int nPivot = pArray[nLeft];
	int nPartition = nLeft + 1;

	for (int i = nLeft + 1; i <= nRight; ++i) {
		if (nPivot > pArray[i]) {
			std::swap(pArray[nPartition++], pArray[i]);
		}
	}

	std::swap(pArray[nPartition - 1], pArray[nLeft]);

	return nPartition - 1;
}

void QuickSort(int* pArray, int nLeft, int nRight) {
	//Quick sort is a recursive algorithm, which works by choosing a pivot
	//And then move this pivot to its final location such that elements to the 
	//left of the pivot are less than the pivot and elements to the right of 
	//the pivot are more than the pivot. Then recursively perform this step on 
	// the left and right parts at the end the array will be sorted.
	//Quick Sort has an everage complexity of O(nlog n), whereas Merge Sort 
	//has a worse case complexitiy of O(nlog n)
	if (nLeft >= nRight)
		return;

	int nPartition = Partition(pArray, nLeft, nRight);
	QuickSort(pArray, nLeft, nPartition - 1);
	QuickSort(pArray, nPartition + 1, nRight);
}

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
		for (size_t i = 0; i < nSize; ++i) {
			cin >> pArray[i];
		}

		//The approach would be to sort the array 
		//and then start two pointers one from begining and one from end
		//start from end.
		//First step remove the max which would be at last
		//2nd step remove the first element, basically move the pointer to
		//the next element and delete that particular element from the memory
		//keep doing this till we have only 1 element remainig.
		QuickSort(pArray, 0, nSize - 1);
		int nEnd(nSize - 1), nBegin(0), nRemainingElements(nSize);

		bool bToggle = true;
		while (nRemainingElements > 1) {
			//First remove the last element
			if (bToggle) {
				//remove the last element
				nEnd--;
			}
			else {
				nBegin++;
			}
			nRemainingElements--;
			bToggle = !bToggle;
		}
		
		cout << pArray[nBegin] << endl;
		delete[] pArray;
		pArray = nullptr;
	}
	return 0;
}