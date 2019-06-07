#include <vector>
#include <iostream>

template <class T> T MajorityElementDivideAndConquer(std::vector<T>& vecList) {

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

	int nMajorityElement = MajorityElementNaive(vecList);
	std::cout << nMajorityElement;

	return 0;
}