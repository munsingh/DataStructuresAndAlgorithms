#include <vector>
//#include <random>
#include <iostream>
#include <algorithm>
//#include <time.h>

template <class T> int BinarySearchRecursive(std::vector<T>& vecNumbers, size_t nLow, size_t nHigh, const T& oData) {
	if (nHigh >= nLow) {
		size_t nMid = nLow + (nHigh - nLow) / 2;
		if (vecNumbers[nMid] == oData)
			return static_cast<int> (nMid);
		else if (vecNumbers[nMid] < oData) {
			return BinarySearchRecursive(vecNumbers, nMid + 1, nHigh, oData);
		}
		else if (vecNumbers[nMid] > oData) {
			return BinarySearchRecursive(vecNumbers, nLow, nMid - 1, oData);
		}
		else {
			return -1;//should not come here
		}
	}
	return -1;
}

template <class T> int BinarySearchIterative(std::vector<T>& vecNumbers, size_t nLow, size_t nHigh, const T& oData) {
	while (nLow <= nHigh) {
		/*int nMid = static_cast<int>(nLow + (nHigh - nLow) / 2);*/
		int nMid = static_cast<int>((nHigh + nLow) / 2);
		if (vecNumbers[nMid] == oData) {
			return nMid;
		}
		else if (vecNumbers[nMid] < oData) {
			//look into the 2nd half
			nLow = nMid + 1;
		}
		else if (vecNumbers[nMid] > oData) {
			nHigh = nMid - 1;
		}
	}

	return -1; //not found
}

template <class T> int BinarySearchIterativeOptimized(std::vector<T>& vecNumbers, size_t nLow, size_t nHigh, const T& oData) {
	int nMid = 0;
	while (nHigh - nLow > 1) {
		nMid = static_cast<int>(nLow + (nHigh - nLow) / 2);
		if (vecNumbers[nMid] <= oData) {
			nLow = nMid;
		}
		else {
			nHigh = nMid;
		}
	}

	if (vecNumbers[nLow] == oData)
		return static_cast<int>(nLow);
	else
		return -1;

}

int main(int /*nArgc*/, char** /*pArgv*/) {
	int nCount = 0;
	std::cin >> nCount;

	//List<int> oList;
	std::vector<int> vecNumbers(nCount);

	//Binary search works on a sorted array
	//the Approach is to divide the array into two.
	//Check if the item we are looking for is less than equal to or greater than the mid-point
	//If it is less than the mid-point, then we discard the greater than the mid-point portion
	//and focus on the less than point
	//We keep doing this unless we find the number
	//There are two approaches for this
	//1. Recursion
	//2. Iterative.
	//std::mt19937 rng; //Random Number Generator
	//rng.seed(time(NULL) );

	//std::uniform_int_distribution<int> oDistN(1, nCount);
	//int nNumber = 0;
	for (int i = 0; i < nCount; ++i) {
		//nNumber = oDistN(rng);
		//std::cout << nNumber;
		/*if (i < nCount)
			std::cout << " ";*/
		std::cin >> vecNumbers[i];
	}

	std::sort(vecNumbers.begin(), vecNumbers.end());

	int nNumberOfKeys;/* = oDistN(rng);*/
	std::cin >> nNumberOfKeys;
	std::vector<int> vecKeys(nNumberOfKeys);
	for (int i = 0; i < nNumberOfKeys; i++) {
		std::cin >> vecKeys[i];
	}

	for (int i = 0; i < nNumberOfKeys; i++) {
		int nIndex = BinarySearchIterativeOptimized(vecNumbers, 0, vecNumbers.size(), vecKeys[i]);
		std::cout << nIndex << " ";
	}
	
	return 0;
}