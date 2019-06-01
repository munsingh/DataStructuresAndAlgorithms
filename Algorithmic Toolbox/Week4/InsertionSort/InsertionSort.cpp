#include <vector>
#include <iostream>

template <class T> void InsertionSort(std::vector<T>& vecList, int nNumberOfElements) {
	//Insertion sort works the way many people would sort a hand of playing cards
	//1. Start with an empty hand
	//2. Pick a card from the list
	//3. Insert it into the correct position in the fill hand.
	//4. To find the exact position compare with the elements in the hand
	T oElement;
	for (int i = 1; i < nNumberOfElements; ++i) {
		oElement = vecList[i];
		int j = i - 1;
		while( j >= 0 ) {
			if (vecList[j] > oElement) {
				vecList[j + 1] = vecList[j];
				--j;
			}
			else
				break;
		}
		vecList[j + 1] = oElement;
	}
}

int main(int nArgv, char** pArgc) {
	//get the number of elements
	int nNumberOfElements;
	std::cin >> nNumberOfElements;

	std::vector<int> vecList(nNumberOfElements);

	for (int i = 0; i < nNumberOfElements; ++i) {
		std::cin >> vecList[i];
	}

	//sort it using insertion srort
	InsertionSort(vecList, nNumberOfElements);

	for (int i = 0; i < nNumberOfElements; ++i)
		std::cout << vecList[i] << " ";
	
	return 0;

}
