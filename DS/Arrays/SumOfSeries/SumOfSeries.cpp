#include <iostream>

using namespace std;

int main(int nArgc, char** pArgv) {
	//The first line in the input contains the number of test cases
	int nNumberOfTestCases;
	cin >> nNumberOfTestCases;

	while (nNumberOfTestCases-- > 0) {
		//The next line contains the size of the array
		int64_t nSeries;
		cin >> nSeries;

		int64_t nSum(0);

		for (int64_t i = 1; i <= nSeries; ++i) {
			nSum += i;
		}

		cout << nSum << endl;
	}
	return 0;
}