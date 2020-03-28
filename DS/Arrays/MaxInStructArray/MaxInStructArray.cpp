#include <iostream>
#include <stdlib.h>
using namespace std;

//Given a struct array of type Height, having two elements feet and inches. 
//Find the maximum height, where height is calculated sum of feet and inches 
//after converting feet into inches.

struct Height{
	int nFeet;
	int nInches;

};

int main(int argc, char** pArgv) {
	size_t nNumberOfInputs;
	cin >> nNumberOfInputs;

	while (nNumberOfInputs--) {
		int nSize;
		cin >> nSize;

		Height* pArray = new Height[nSize];
		for (int i = 0; i < nSize * 2; ++i) {
			cin >> pArray[i].nFeet;
			cin >> pArray[i].nInches;
		}

		int nMaxHeight = INT_MIN, nHeight(0);
		for (int i = 0; i < nSize; ++i) {
			nHeight = pArray[i].nFeet * 12 + pArray[i].nInches;
			if (nHeight > nMaxHeight) {
				nMaxHeight = nHeight;
			}
		}

		cout << nMaxHeight << endl;
		delete[] pArray;
	}

	return 0;
}