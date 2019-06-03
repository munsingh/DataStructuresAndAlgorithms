#include <vector>
#include <iostream>
#include <algorithm>

template <class T> void CountSort(std::vector<T>& vecList, std::vector<T>& vecSortedList) {
	//find the max element in the vecList
	size_t nSize = vecList.size();
	const T nMax = *std::max_element(vecList.begin(), vecList.end());
	const T nMin = *std::min_element(vecList.begin(), vecList.end());
	int nRange = nMax - nMin + 1;

	std::vector<T> vecCount(nRange,0);

	//First build the histogram of the numbers in the count array
	//with minimum being stored at the 0th index
	for (size_t i = 0; i < nSize; ++i) {
		vecCount[vecList[i] - nMin]++;
	}

	////Now perform the prefix sum on the vecCount
	////to determine, for each key, the position range 
	////where the items having that key should be placed in; 
	////prefix sum is y(n)=y(n-1)+x(n)
	//for (size_t i = 1; i < vecCount.size(); ++i) {
	//	vecCount[i] += vecCount[i - 1];
	//}

	//for (size_t i = nSize - 1; i >= 0; i--) {
	//	vecSortedList[vecCount[vecList[i] - nMin] - 1] = vecList[i];
	//	vecCount[vecList[i] - nMin]--;
	//}

	//Now we have the histogram
	//so we start a loop for the size of the vecList
	//and we start populating the 
	int nListIndex = 0;
	for (int i = 0; i < vecCount.size(); ++i) {
		for (int j = 0; j < vecCount[i]; ++j) {
			vecSortedList[nListIndex++] = i + nMin ;
		}
	}
}

int main(int /*nArgv*/, char** /*pArgc*/) {
	//get the number of elements
	int nNumberOfElements;
	std::cin >> nNumberOfElements;
	
	//get the elements
	std::vector<int> vecList(nNumberOfElements);

	for (int i = 0; i < nNumberOfElements; ++i) {
		std::cin >> vecList[i];
	}

	std::vector<int> vecSortedList(nNumberOfElements);

	CountSort(vecList, vecSortedList);
	for (int i = 0; i < nNumberOfElements; ++i) {
		std::cout << vecSortedList[i] << " ";
	}

	return 0;
}