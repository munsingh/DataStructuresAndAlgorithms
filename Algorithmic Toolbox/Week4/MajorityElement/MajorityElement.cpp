#include <vector>
#include <iostream>

template <class T> int Count(std::vector<T>& vecList, T nNumber, int nLow, int nHigh) {
	int nCount = 0;
	for (int i = nLow; i <= nHigh; i++) {
		if (vecList[i] == nNumber ) {
			nCount++;
		}
	}

	return nCount;
}

template <class T> T MajorityElementDivideAndConquer(std::vector<T>& vecList, int nLow, int nHigh) {
	if (nLow == nHigh) {
		return vecList[nLow];
	}

	//recurse on left and right
	int nMid = (nHigh - nLow) / 2 + nLow;
	int nLeft = MajorityElementDivideAndConquer(vecList, nLow, nMid);
	int nRight = MajorityElementDivideAndConquer(vecList, nMid + 1, nHigh);

	//if the two halves agree on the majority element, return it
	if (nLeft == nRight) {
		return nLeft;
	}

	//otherwise, count each element and return the winner
	int nLeftCount = Count(vecList, nLeft, nLow, nHigh);
	int nRightCount = Count(vecList, nRight, nLow, nHigh);

	if (nLeftCount > nMid) {
		return nLeft;
	}
	else if (nRightCount > nMid) {
		return nRight;
	}
	else
		return -1;
}

template <class T> T MajorityElementNaive(std::vector<T>& vecList) {
	//This is a naive implementation of finding majority element in a list
	//Majority element is a decision rule, which selects the alternative which 
	//has a mojority, that is, more than half the votes.

	T nMajorityElement = 0;

	int nCount = 0;
	int nMaxCount = 0;
	size_t nNumberOfElements = vecList.size();
	size_t nMaxCountIndex = 0;
	for (size_t i = 0; i < nNumberOfElements; i++) {
		nCount = 0;
		for (size_t j = 0; j < nNumberOfElements; j++) {
			if (vecList[i] == vecList[j])
				nCount++;
		}

		if (nMaxCount < nCount) {
			nMaxCount = nCount;
			nMaxCountIndex = i;
		}
	}

	if (nMaxCount > nNumberOfElements / 2) {
		return vecList[nMaxCountIndex];
	}

	return nMajorityElement;
}

int main(int /*nArgv*/, char** /*pArgc*/) {
	int nNumberOfElements = 0;
	std::cin >> nNumberOfElements;

	std::vector<int> vecList(nNumberOfElements);
	for (int i = 0; i < nNumberOfElements; i++) {
		std::cin >> vecList[i];
	}

	//int nMajorityElement = MajorityElementNaive(vecList);
	int nMajorityElement = MajorityElementDivideAndConquer(vecList, 0, nNumberOfElements - 1);
	if (nMajorityElement > 0)
		std::cout << 1;
	else
		std::cout << 0;

	return 0;
}