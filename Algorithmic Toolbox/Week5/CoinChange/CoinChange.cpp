#include <vector>
#include <iostream>
#include <cassert>

void Partition(std::vector<int>& vecItems, int nLeft, int nRight,
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

void QuickSort(std::vector<int>& vecItems, int nLeft, int nRight) {
	//Use the optimized quick sort using the two partition method
	if (nLeft >= nRight) {
		return;
	}

	int nPartition1 = 0, nPartition2 = 0;
	Partition(vecItems, nLeft, nRight, nPartition1, nPartition2);
	QuickSort(vecItems, nLeft, nPartition1);
	QuickSort(vecItems, nPartition2, nRight);
}

int GetAppropriteDenomination(std::vector<int>& vecCoins, int nMoney) {
	int nDenomination = 0;
	for (auto it = vecCoins.begin(); it != vecCoins.end(); it++) {
		if (*it <= nMoney) {
			nDenomination = *it;
			//delete this from the vec of coins
			vecCoins.erase(it);
			return nDenomination;
		}
	}

	return nDenomination;
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
	int nNumberOfCoins = 0;
	std::cout << "Enter the number of coins: ";
	std::cin >> nNumberOfCoins;

	std::cout << "Enter the coin denominations (space separated):";
	std::vector<int> vecCoins(nNumberOfCoins);
	for (int i = 0; i < nNumberOfCoins; i++) {
		std::cin >> vecCoins[i];
	}

	//sort the number of coins in descending orders.
	QuickSort(vecCoins, 0, static_cast<int>(vecCoins.size() - 1));

	std::cout << "Enter the money to be changed:";
	int nMoney = 0;
	std::cin >> nMoney;

	std::vector<int> vecChange;
	ChangeMoney_Greedy(nMoney, vecCoins, vecChange);

	for (auto it = vecChange.begin(); it != vecChange.end(); it++) {
		std::cout << *it << " ";
	}

	return  0;
}
