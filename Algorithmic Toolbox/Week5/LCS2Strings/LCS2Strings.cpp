#include <vector>
#include <iostream>
#include <algorithm>

template <class T>
int GetLCSRecursively(const std::vector<T>& vecItem1,
					  const std::vector<T>& vecItem2,
					 int i, int j) {
	//This solves the problem recursively
	if (i == vecItem1.size() || j == vecItem2.size()) {
		return 0;
	}

	if (vecItem1[i] == vecItem2[j]) {
		return 1 + GetLCSRecursively(vecItem1, vecItem2, i + 1, j + 1);
	}
	else {
		return std::max(GetLCSRecursively(vecItem1, vecItem2, i + 1, j),
						GetLCSRecursively(vecItem1, vecItem2, i, j + 1));
	}
}

template <class T>
int GetLCSRecursivelyMemoization(const std::vector<T>& vecItem1,
								 const std::vector<T>& vecItem2,
								 int i,
								 int j,
								 std::vector<std::vector<T>> &vecTables ) {
	//Here we store the result in the appropriate cell in the table
	//and before callng the function recursively, we check if the value exists
	//or not
	if (i == vecItem1.size() || j == vecItem2.size()) {
		return 0;
	}

	if (vecItem1[i] == vecItem2[j]) {
		if (vecTables[i+1][j+1] == -1) {
			vecTables[i+1][j+1] = 1 + GetLCSRecursivelyMemoization(vecItem1,
															   vecItem2,
															   i + 1,
															   j + 1,
															   vecTables);

		}
		return vecTables[i + 1][j + 1];
	}
	else {
		int nLeft = vecTables[i + 1][j];
		if ( nLeft == -1) {
			//Not calculated
			nLeft = GetLCSRecursively(vecItem1, vecItem2, i + 1, j);
			vecTables[i + 1][j] = nLeft;
		}
		int nRight = vecTables[i][j + 1];
		if (nRight == -1) {
			nRight = GetLCSRecursively(vecItem1, vecItem2, i, j + 1);
			vecTables[i][j + 1] = nRight;
		}

		return std::max(nLeft, nRight);
	}
}

template <class T>
int GetLCSDynamicProgramming(const std::vector<T>& vecItem1,
							 const std::vector<T>& vecItem2) {
	//we create a 2D table
	std::vector< std::vector<int>> vecTables(vecItem1.size() + 1,
											 std::vector<int>(vecItem2.size()
																+ 1));
	for (int nRow = 0; nRow < vecItem1.size() + 1; nRow++) {
		vecTables[nRow][0] = 0;
	}

	for (int nCol = 0; nCol < vecItem2.size() + 1; nCol++) {
		vecTables[0][nCol] = 0;
	}

	//Thee first row and column arere all 0
	//start  filling up row by row and column by column
	//start with 1st row and 1stt column
	for (int nCol = 1; nCol < vecItem2.size() + 1; nCol++) {
		for (int nRow = 1; nRow < vecItem1.size() + 1; nRow++) {
			if (vecItem1[nRow - 1] == vecItem2[nCol - 1]) {
				vecTables[nRow][nCol] = 1 + vecTables[nRow - 1][nCol - 1];
			}
			else {
				vecTables[nRow][nCol] = std::max(vecTables[nRow - 1][nCol], vecTables[nRow][nCol - 1]);
			}
		}
	}

	return vecTables[vecItem1.size()][vecItem2.size()];
}

int main(int /*nArgc*/, char** /*pArgv*/) {
	int nItem1Count;
	std::cin >> nItem1Count;
	std::vector< int > vecItem1(nItem1Count);
	for (int i = 0; i < nItem1Count; i++) {
		std::cin >> vecItem1[i];
	}

	int nItem2Count;
	std::cin >> nItem2Count;
	std::vector< int > vecItem2(nItem2Count);
	for (int i = 0; i < nItem2Count; i++) {
		std::cin >> vecItem2[i];
	}

	//std::cout << GetLCSRecursively(vecItem1, vecItem2, 0, 0);

	/*std::vector<std::vector<int>> vecTables(nItem1Count + 1,
								  std::vector<int>(nItem2Count + 1, -1));
	std::cout << GetLCSRecursivelyMemoization(vecItem1, vecItem2, 0, 0, vecTables);*/

	std::cout << GetLCSDynamicProgramming(vecItem1, vecItem2);
	return 0;
}