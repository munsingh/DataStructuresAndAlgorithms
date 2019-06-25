#include <vector>
#include <iostream>
#include <cassert>
#include <algorithm>

void PartitionAscending(std::vector<int>& vecItems, int nLeft, int nRight,
						int& nPartition1,
						int& nPartition2) {
	if (nRight - nLeft < 2) {
		if (vecItems[nRight] > vecItems[nLeft]) {
			std::swap(vecItems[nRight], vecItems[nLeft]);
		}

		nPartition1 = nLeft;
		nPartition2 = nRight;
	}

	int nPivot = vecItems[nRight];
	int i = nLeft;

	while (i <= nRight) {
		if (nPivot > vecItems[i]) {
			std::swap(vecItems[i++], vecItems[nLeft++]);
		}
		else if (nPivot < vecItems[i]) {
			std::swap(vecItems[i], vecItems[nRight--]);
		}
		else {
			i++;
		}
	}

	nPartition1 = nLeft - 1;
	nPartition2 = i;
}

void PartitionDescending(std::vector<int>& vecItems, int nLeft, int nRight,
			   int& nPartition1,
			   int& nPartition2) {
	if (nRight - nLeft < 2) {
		if (vecItems[nRight] > vecItems[nLeft]) {
			std::swap(vecItems[nRight], vecItems[nLeft]);
		}

		nPartition1 = nLeft;
		nPartition2 = nRight;
	}

	int nPivot = vecItems[nRight];
	int i = nLeft;
	while (i <= nRight) {
		if (nPivot < vecItems[i]) {
			std::swap(vecItems[i++], vecItems[nLeft++]);
		}
		else if (nPivot > vecItems[i]) {
			std::swap(vecItems[i], vecItems[nRight--]);
		}
		else
			i++;
	}

	nPartition1 = nLeft - 1;
	nPartition2 = i;
}

void QuickSort(std::vector<int>& vecItems, int nLeft, int nRight, bool bAscending = true) {
	//Use the optimized quick sort using the two partition method
	if (nLeft >= nRight) {
		return;
	}

	int nPartition1 = 0, nPartition2 = 0;
	if (bAscending) {
		PartitionAscending(vecItems, nLeft, nRight, nPartition1, nPartition2);
	}
	else {
		PartitionDescending(vecItems, nLeft, nRight, nPartition1, nPartition2);
	}
	QuickSort(vecItems, nLeft, nPartition1, bAscending);
	QuickSort(vecItems, nPartition2, nRight, bAscending);
}

int GetAppropriteDenomination(std::vector<int>& vecCoins, int nMoney) {
	int nDenomination = 0;
	for (auto it = vecCoins.begin(); it != vecCoins.end(); it++) {
		if (*it <= nMoney) {
			nDenomination = *it;
			//delete this from the vec of coins
			//vecCoins.erase(it);
			return nDenomination;
		}
	}

	return nDenomination;
}

int ChangeMoney_DynamicProgramming(int nMoney, std::vector<int>& vecCoins, std::vector<int>& vecChange) {
	////we create a 2 dimensional table.

	////now we have a 2d table, the table is referenced by [row][column] so which
	////would be [y][x], if x is the horizontal axis.
	//std::vector< std::vector<int>> arrTables(vecCoins.size() + 1, std::vector<int>(nMoney + 1));
	////first row is all 1s
	//for (int nCol = 0; nCol <= nMoney; nCol++) {
	//	arrTables[0][nCol] = 1;
	//}

	//for (int nRow = 1; nRow <= vecCoins.size(); nRow++) {
	//	arrTables[nRow][0] = 0;
	//}

	////we start from 1 to last row
	////and from 1 to last column
	////  0 1 2 3 4 5 6 7
	////0 1 1 1 1 1 1 1 1
	////1 0
	////3 0
	////5 0
	//for (int nRow = 1; nRow <= vecCoins.size(); nRow++) {
	//	for (int nCol = 1; nCol <= nMoney; nCol++) {
	//		if (nCol < vecCoins[nRow - 1]) {
	//			arrTables[nRow][nCol] = arrTables[nRow - 1][nCol];
	//		}
	//		else {
	//			arrTables[nRow][nCol] = arrTables[nRow - 1][nCol] + arrTables[nRow][nCol - vecCoins[nRow - 1]];
	//		}
	//	}
	//}

	//return arrTables[vecCoins.size()][nMoney];

	std::vector< int > vecTable(nMoney + 1, INT16_MAX);
	vecTable[0] = 0;

	for (int nCol = 1; nCol <= nMoney; nCol++) {
		for (int j = 0; j < vecCoins.size(); j++) {
			if (vecCoins[j] <= nCol) {
				int nSubRes = vecTable[nCol - vecCoins[j]];
				if (nSubRes != INT16_MAX && nSubRes + 1 < vecTable[nCol]) {
					vecTable[nCol] = nSubRes + 1;
				}
			}
		}
	}

	return vecTable[nMoney];
}

void ChangeMoney_Greedy(int nMoney, std::vector<int>& vecCoins, std::vector<int>& vecChange) {
	//vecCoins contains the coins available
	//vecChange is to populated with the coins from the vecCoins which will
	//change the money nMoney

	int nDenomination = 0;
	while (nMoney > 0) {
		//Get the first coin which is less than nMoney
		nDenomination = GetAppropriteDenomination(vecCoins, nMoney);
		if (nDenomination > 0) {
			nMoney -= nDenomination;
			vecChange.push_back(nDenomination);
		}
		else if (nDenomination == 0) {
			vecChange.push_back(-1);
			break;
		}
		else {
			assert(false);
		}
	}
}

int main(int /*nArgv*/, char** /*pArgc*/) {

	//int nNumberOfCoins = 3;
	/*std::cout << "Enter the number of coins: ";
	std::cin >> nNumberOfCoins;

	std::cout << "Enter the coin denominations (space separated):";*/
	std::vector<int> vecCoins{ 1, 3, 4 };
	/*for (int i = 0; i < nNumberOfCoins; i++) {
		std::cin >> vecCoins[i];
	}*/

	//sort the number of coins in descending orders.
	//For greedy decsending for DP ascending order
	QuickSort(vecCoins, 0, static_cast<int>(vecCoins.size() - 1));

	//std::cout << "Enter the money to be changed:";
	int nMoney = 0;
	std::cin >> nMoney;

	std::vector<int> vecChange;
	//ChangeMoney_Greedy(nMoney, vecCoins, vecChange);
	std::cout << ChangeMoney_DynamicProgramming(nMoney, vecCoins, vecChange);

	/*for (auto it = vecChange.begin(); it != vecChange.end(); it++) {
		std::cout << *it << " ";
	}*/

	return  0;
}
