#include <vector>
#include <iostream>
#include <algorithm>

template <class T>
int GetLCS(const std::vector<T>& vecSequence1,
	const std::vector<T>& vecSequence2,
	const std::vector<T>& vecSequence3) {
	//We create a 3D table, bascically a vector of a vector of a vector
	std::vector< std::vector< std::vector<int>>> vecTables;

	//Resize the array
	//Rows i.e. height using index i
	vecTables.resize(vecSequence1.size() + 1);
	for (int j = 0; j < vecSequence1.size() + 1; j++) {
		vecTables[j].resize(vecSequence2.size() + 1);

		for (int k = 0; k < vecSequence2.size() + 1; k++) {
			vecTables[j][k].resize(vecSequence3.size() + 1);
		}
	}

	for (int i = 0; i < vecSequence1.size() + 1; i++) {
		vecTables[i][0][0] = 0;
	}

	for (int j = 0; j < vecSequence2.size() + 1; j++) {
		vecTables[0][j][0] = 0;
	}

	for (int k = 0; k < vecSequence3.size() + 1; k++) {
		vecTables[0][0][k] = 0;
	}

	for (int i = 1; i < vecSequence1.size() + 1; i++) {
		for (int j = 1; j < vecSequence2.size() + 1; j++) {
			for (int k = 1; k < vecSequence3.size() + 1; k++) {
				if (vecSequence1[i - 1] == vecSequence2[j - 1] && vecSequence2[j - 1] == vecSequence3[k - 1]) {
					vecTables[i][j][k] = 1 + vecTables[i - 1][j - 1][k - 1];
				}
				else {
					vecTables[i][j][k] = std::max({vecTables[i - 1][j][k],
												   vecTables[i][j - 1][k],
												   vecTables[i][j][k - 1] });
				}
			}
		}
	}
	
	return vecTables[vecSequence1.size()]\
					[vecSequence2.size()]\
					[vecSequence3.size()];
}
int main(int /*nArgc*/, char** /*pArgv*/) {
	//get the three sequences
	int nSequence1Size, nSequence2Size, nSequence3Size;

	std::cin >> nSequence1Size;
	std::vector< int > vecSequence1(nSequence1Size);
	for (int i = 0; i < nSequence1Size; i++) {
		std::cin >> vecSequence1[i];
	}

	std::cin >> nSequence2Size;
	std::vector< int > vecSequence2(nSequence2Size);
	for (int i = 0; i < nSequence2Size; i++) {
		std::cin >> vecSequence2[i];
	}

	std::cin >> nSequence3Size;
	std::vector< int > vecSequence3(nSequence3Size);
	for (int i = 0; i < nSequence3Size; i++) {
		std::cin >> vecSequence3[i];
	}

	std::cout << GetLCS(vecSequence1, vecSequence2, vecSequence3);

	return 0;
}