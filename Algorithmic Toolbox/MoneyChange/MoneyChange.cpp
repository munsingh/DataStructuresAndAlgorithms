#include <iostream>
#include <vector>

int get_change(int m) {
	int nCoinArray[] = { 10, 5, 1 };
	int nNumberOfCoins = sizeof(nCoinArray) / sizeof(int);

	std::vector< int > vecCoinCounter(nNumberOfCoins);
	int nIndex = 0;

	while (m > 0) {
		//Start with the biggest coin
		//Check if the biggest coin is less than m, if yes, use this coin
		//otherwise move to the next smallest coin
		
		while (nIndex <= nNumberOfCoins) {
			if (m >= nCoinArray[nIndex]) {
				m -= nCoinArray[nIndex];
				
				vecCoinCounter[nIndex] = vecCoinCounter[nIndex] + 1;
				break;
			}
			++nIndex;
		}
	}
	
	int n = 0;
	for (size_t nIndex = 0; nIndex < vecCoinCounter.size(); ++nIndex ) {
		n += vecCoinCounter[nIndex];
	}

	return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
