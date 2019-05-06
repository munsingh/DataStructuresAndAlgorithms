#include <iostream>
#include <vector>

using std::vector;

void optimal_summands(int n, vector<int>& vecSummands) {
	//write your code here
	//Start a loop, the first summand will be the lowest number,
	//next number is the remainder from the previous operation
	//Note: This time the summand has to be greater than the previous summand
	//and cannot be same as any of the previous summand
	//So
	for (int k = n, l = 1; k > 0; ++l) {
		if (k <= 2 * l) {
			vecSummands.push_back(k);
			k -= k;
		}
		else {
			vecSummands.push_back(l);
			k -= l;
		}
	}
}

int main() {
	int n;
	std::cin >> n;
	vector<int> vecSummands;
	optimal_summands(n, vecSummands);
	

	std::cout << vecSummands.size() << '\n';
	for (size_t i = 0; i < vecSummands.size(); ++i) {
		std::cout << vecSummands[i] << ' ';
	}
}
