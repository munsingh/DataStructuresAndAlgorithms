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
template <class T > void Merge(std::vector<T>& vecList, size_t nLeft, size_t nMid, size_t nRight) {
	size_t nLeftSize = nMid - nLeft + 1;
	size_t nRightSize = nRight - nMid;

	//create two vectors for left and right
	std::vector<T> vecLeft(nLeftSize);
	std::vector<T> vecRight(nRightSize);

	//Populate vecLeft and vecRight
	for (size_t i = 0; i < nLeftSize; ++i) {
		vecLeft[i] = vecList[nLeft + i];
	}

	for (size_t i = 0; i < nRightSize; ++i) {
		vecRight[i] = vecList[nMid + i];
	}

	//how we iterate the two temp arrays until they are empty
	size_t i = 0, j = 0, k = nLeft;
	while (i < nLeftSize && j << nRightSize) {
		if (vecLeft[i] < vecRight[j]) {
			vecList[k] = vecLeft[i++];
		}
		else {
			vecList[k] = vecRight[j++];
		}
		++k;
	}

	//Copy the remaining of left and right to the actual vector
	while (i < nLeftSize) {
		vecList[k++] = vecLeft[i++];
	}

	while (j < nRightSize) {
		vecList[k++] = vecRight[j++];
	}
}

template <class T> void MergeSort(std::vector<T>& vecList, size_t nLeft, size_t nRight) {
	//find the mid node
	
	if (nLeft < nRight) {
		size_t nMid = (nLeft + nRight) / 2;

		MergeSort(vecList, nLeft, nMid);
		MergeSort(vecList, nMid + 1, nRight);
		Merge(vecList, nLeft, nMid, nRight);
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

	MergeSort(vecList, 0, vecList.size());
	for (int i = 0; i < nNumberOfElements; ++i) {
		std::cout << vecList[i] << " ";
	}

	return 0;
}