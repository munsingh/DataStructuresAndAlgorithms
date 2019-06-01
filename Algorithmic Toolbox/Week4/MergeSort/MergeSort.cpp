#include <vector>
#include <iostream>

/*
 This function makes an empty array of the same size as original array
 We iterate the two sides i.e., left t mid and mid+1 to right, until we have reached the end
 if the first element of left is less than that of the right, then move this element to end of 
 the copy arrary, else move the first from the right to the end
 Once out of the loop, move the the rest of the left and right to the end.
 the temp array is the new array, which has to be worked upon.
*/
template <class T > void Merge(std::vector<T>& vecList, std::vector<T>& vecLeft, std::vector<T>& vecRight) {
	size_t nLeftSize = vecLeft.size();
	size_t nRightSize = vecRight.size();
	size_t nListSize = vecList.size();

	size_t i = 0, j = 0, k = 0;
	
	//create two vectors for left and right
	//how we iterate the two temp arrays until they are empty
	while (i < nLeftSize && j < nRightSize) {
		if (vecLeft[i] < vecRight[j]) {
			vecList[k++] = vecLeft[i++];
		}
		else {
			vecList[k++] = vecRight[j++];
		}
	}

	//Copy the remaining of left and right to the actual vector
	while (i < nLeftSize) {
		vecList[k++] = vecLeft[i++];
	}

	while (j < nRightSize) {
		vecList[k++] = vecRight[j++];
	}
}

template <class T> void MergeSort(std::vector<T>& vecList) {
	//find the mid node
	size_t nLength = vecList.size();
	
	if (nLength < 2) {
		return;
	}
	else {
		size_t nMid = nLength / 2;
		std::vector<T> vecLeft(nMid);
		std::vector<T> vecRight(nLength - nMid);

		size_t k = 0;
		for (size_t i = 0; i < nMid; ++i) {
			vecLeft[i] = vecList[k++];
		}

		for (size_t i = 0; i < nLength - nMid; ++i) {
			vecRight[i] = vecList[k++];
		}

		MergeSort(vecLeft);
		MergeSort(vecRight);
		Merge(vecList, vecLeft, vecRight);
	}
}

/*
 This implements Merge sort techniques. Merge sort basically requires splitting the problem set in smaller problems, 
 */
int main(int nArgc, char** pArgv) {
	int nNumberOfElements;
	std::cin >> nNumberOfElements;

	std::vector< int > vecList(nNumberOfElements);

	for (int i = 0; i < nNumberOfElements; ++i) {
		std::cin >> vecList[i];
	}

	MergeSort(vecList);
	for (int i = 0; i < nNumberOfElements; ++i) {
		std::cout << vecList[i] << " ";
	}

	return 0;
}