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

/*
	The Boyer–Moore majority vote algorithm is an algorithm for finding the majority of a sequence of 
	elements using linear time and constant space. It is named after Robert S. Boyer and J Strother Moore, 
	who published it in 1981,[1] and is a prototypical example of a streaming algorithm. 

	This algorithm works in O(n) complexity. Basically iterate the array
	and start with the 1st element, any time it is found again, increment the
	count, if not found then decrement the count. When count becomes 0
	then the majority element candidate is reset to the latest index
	and the count is reset to 0

	Once a candidate is identified, do a 2nd pass in O(n) and identify
	if the candidate occures more than n/2 in the array.
*/
template <class T> T MajorityElementMooresVotingAlgorithm(std::vector<T>& vecList) {
	size_t	nSize			= vecList.size();
	size_t	nMajorityIndex	= 0;
	int		nCount = 1;

	for (size_t i = 0; i < nSize; i++) {
		if (vecList[nMajorityIndex] == vecList[i]) {
			nCount++;
		}
		else {
			nCount--;
		}

		if (0 == nCount) {
			//reset
			nMajorityIndex = i;
			nCount = 1;
		}
	}

	//element at nMajorityIndex is our candidate
	//Now do a second pass and check
	nCount = 0;
	for (size_t i = 0; i < nSize; i++) {
		if (vecList[nMajorityIndex] == vecList[i])
			nCount++;

		if (nCount > nSize / 2)
			return vecList[nMajorityIndex];
	}

	return -1;
}

template <class T> T MajorityElementDivideAndConquer(std::vector<T>& vecList, int nLow, int nHigh) {

	if (nLow > nHigh) {
		return -1;
	}

	if (nLow == nHigh) {
		return vecList[nLow];
	}

	//recurse on left and right
	int nMid = (nHigh - nLow) / 2 + nLow;
	int nLeft = MajorityElementDivideAndConquer(vecList, nLow, nMid);
	int nRight = MajorityElementDivideAndConquer(vecList, nMid + 1, nHigh);

	if (nLeft == -1 && nRight != -1) {
		//Not there in the left but is there in the right side
		int nRightCount = Count(vecList, nRight, nLow, nHigh);
		if (nRightCount > (nHigh - nLow + 1) / 2) {
			return nRight;
		}
		else
			return -1;
	}
	else if (nLeft != -1 && nRight == -1) {
		//there in right but not in left
		int nLeftCount = Count(vecList, nLeft, nLow, nHigh);
		if (nLeftCount > (nHigh - nLow + 1) / 2) {
			return nLeft;
		}
		else
			return -1;
	}
	else if (nLeft != -1 && nRight != -1) {
		//present in both left and right
		int nLeftCount = Count(vecList, nLeft, nLow, nHigh);
		int nRightCount = Count(vecList, nRight, nLow, nHigh);;
		if (nRightCount > (nHigh - nLow + 1) / 2) {
			return nRight;
		}
		else if (nLeftCount > (nHigh - nLow + 1) / 2) {
			return nLeft;
		}
		else
			return -1;
	}
	else {
		//not in both
		return -1;
	}

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
	//int nMajorityElement = MajorityElementDivideAndConquer(vecList, 0, nNumberOfElements - 1);
	int nMajorityElement = MajorityElementMooresVotingAlgorithm(vecList);
	if (nMajorityElement > 0)
		std::cout << 1;
	else
		std::cout << 0;

	return 0;
}