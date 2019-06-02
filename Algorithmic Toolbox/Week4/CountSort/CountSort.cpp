#include <vector>
#include <iostream>

template <class T> void CountSort(std::vector<T>& vecList, std::vector<T>& vecSortedList, int nMax) {

}

int main(int /*nArgv*/, char** /*pArgc*/) {
	//get the number of elements
	int nNumberOfElements;
	std::cin >> nNumberOfElements;
	
	//get the maximum range of the elements i.e. 1 to nMax
	int nMax;
	std::cin >> nMax;

	//get the elements
	std::vector<int> vecList(nNumberOfElements);

	for (int i = 0; i < nNumberOfElements; ++i) {
		std::cin >> vecList[i];
	}

	std::vector<int> vecSortedList;
	CountSort(vecList, vecSortedList, nMax);
	for (int i = 0; i < nNumberOfElements; ++i) {
		std::cout << vecSortedList[i] << " ";
	}

	return 0;
}