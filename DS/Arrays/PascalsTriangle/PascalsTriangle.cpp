#include <iostream>
using namespace std;

int main(int nArgc, char** pArgv) {
	//The first line in the input contains the number of test cases
	int nNumberOfTestCases;
	cin >> nNumberOfTestCases;

	while (nNumberOfTestCases-- > 0) {
		//The next line contains the size of the array
		int nLevel(0);
		cin >> nLevel;

		//for pascals triangle of nLevelIndex levels the number of elements
		//will be n(n+2)/2. So we create an array of this size
		//Now read the array data
		
		
		for (int i = 1; i <= nLevel; ++i) {
			//each level has level number of elements
			int nCoeff = 1;
			for (int j = 1; j <= i; ++j) {
				if (i == nLevel) {
					cout << nCoeff << " ";
				}
				nCoeff = nCoeff * (i - j) / j;
			}
		}
		cout << endl;
	}
	return 0;
}