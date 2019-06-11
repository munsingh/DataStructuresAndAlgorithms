#include <vector>
#include <iostream>
#include <utility>

template <class T> size_t Merge(std::vector<T>& vecList, std::vector<T>& vecLeft, std::vector<T>& vecRight, std::vector<std::pair<T,T>>& vecInversionPairs) {
	size_t nLeftSize = vecLeft.size();
	size_t nRightSize = vecRight.size();
	size_t nListSiz = vecList.size();
	size_t nInversionCount = 0;

	size_t i = 0, j = 0, k = 0;
	while (i < nLeftSize && j < nRightSize) {
		if (vecLeft[i] <= vecRight[j]) {
			vecList[k++] = vecLeft[i++];
		}
 		else {
			vecList[k++] = vecRight[j];
			vecInversionPairs.push_back(std::make_pair(vecLeft[i], vecRight[j++]));
			nInversionCount += (nLeftSize - i);
		}
	}

	//Now copy the remaining elements of left and right to the list
	while (i < nLeftSize) {
		vecList[k++] = vecLeft[i++];
	}
	
	while (j < nRightSize) {
		vecList[k++] = vecRight[j++];
	}

	return nInversionCount;
}

template <class T> size_t MergeSort(std::vector<T>& vecList, std::vector<std::pair<T, T>>& vecInversionPairs) {
	size_t nSize = vecList.size();
	size_t nInversionCount = 0;

	if (nSize < 2) {
		return 0;
	}
	else {
		size_t nMid = nSize / 2;
		std::vector<T> vecLeft(nMid);
		std::vector<T> vecRight(nSize - nMid);
		size_t nIndex = 0;
		for (size_t i = 0; i < nMid; i++) {
			vecLeft[i] = vecList[nIndex++];
		}

		for (size_t i = 0; i < nSize - nMid; i++) {
			vecRight[i] = vecList[nIndex++];
		}

		nInversionCount = MergeSort(vecLeft, vecInversionPairs);
		nInversionCount += MergeSort(vecRight, vecInversionPairs);
		nInversionCount += Merge(vecList, vecLeft, vecRight, vecInversionPairs);
	}

	return nInversionCount;
}

int main(int /*nArgv*/, char** /*pArgc*/) {
	int nNumberOfElements = 0;
	std::cin >> nNumberOfElements;

	std::vector<int> vecList(nNumberOfElements);
	for (int i = 0; i < nNumberOfElements; i++) {
		std::cin >> vecList[i];
	}

	std::vector<std::pair<int, int>> vecInversionPairs;
	size_t nInversionCount = MergeSort(vecList, vecInversionPairs);
	std::cout << nInversionCount;
	return 0;
}