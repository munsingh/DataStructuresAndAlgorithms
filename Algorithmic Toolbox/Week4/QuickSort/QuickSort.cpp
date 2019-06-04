#include <vector>
#include <iostream>
#include <algorithm>


template <class T> int Partition(std::vector<T>& vecList, int nLeft, int nRight) {
	//Here we move the pivot to its final location
	//The pivot is the element at the left position
	//the Initial parition is the position next to the left
	//Start a loop from left +1 till the end i.e. right (insclusive)
	//If the pivot is greater than the element
	//then swap the elements at the partition and the current position
	//Move the parition to the next element.
	//Once the loop is done
	//Swap the element before the partition with the left one.
	T nPivot = vecList[nLeft];
	int nPartition = nLeft + 1;
	for (int i = nLeft + 1; i <= nRight; ++i) {
		if (nPivot > vecList[i]) {
			//swap vecList[i] and vecList[nPartition]
			std::swap(vecList[nPartition], vecList[i]);
			nPartition++;
		}
	}

	//Swap vecList[nLeft] and vecList[nParition]
	std::swap(vecList[nPartition -1 ], vecList[nLeft]);
	return nPartition - 1;
}

template <class T> void QuickSort(std::vector<T>& vecList, int nLeft, int nRight) {
	//Quick sort is a recursive algorithm, which works by choosing a pivot
	//And then move this pivot to its final location such that elements to the 
	//left of the pivot are less than the pivot and elements to the right of the pivot
	//are more than the pivot.
	//Then resrusively perform this step on the left and right parts
	//at the end the array will be sorted.
	//Quick Sort has an everage complexity of O(nlog n), whereas Merge Sort has a worse case
	//complexitiy of O(nlog n)

	if (nLeft >= nRight) {
		return;
	}

	int nPartition = Partition(vecList, nLeft, nRight);
	QuickSort(vecList, nLeft, nPartition - 1);
	QuickSort(vecList, nPartition + 1, nRight);
}

int main(int /*nArgv*/, char** /*pArgc*/) {
	//get the number of elements
	int nNumberOfElements;
	std::cin >> nNumberOfElements;

	std::vector<int> vecList(nNumberOfElements);
	for (int i = 0; i < nNumberOfElements; ++i) {
		std::cin >> vecList[i];
	}

	QuickSort(vecList,0, nNumberOfElements - 1);

	for (int i = 0; i < nNumberOfElements; ++i) {
		std::cout << vecList[i] << " ";
	}
}