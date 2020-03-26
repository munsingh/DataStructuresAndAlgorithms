#include <iostream>
using namespace std;

int main(int nArgc, char** pArgv) {
	//The first line in the input contains the number of test cases
	int nNumberOfTestCases;
	cin >> nNumberOfTestCases;

	while (nNumberOfTestCases-- > 0) {
		//The next line contains the skills of first space separated
		int nSize = 3;

		int64_t *pArray1 = new int64_t[nSize];
		int64_t *pArray2 = new int64_t[nSize];

		for (int i = 0; i < nSize; ++i) {
			cin >> pArray1[i];
		}

		for (int i = 0; i < nSize; ++i) {
			cin >> pArray2[i];
		}

		int nAScore(0), nBScore(0);

		for (int i = 0; i < nSize; ++i) {
			if (pArray1[i] > pArray2[i])
				nAScore++;
			else if (pArray1[i] < pArray2[i])
				nBScore++;
			else {
				//do nothing
				;
			}
		}

		cout << nAScore << " " << nBScore << endl;
	}
	return 0;
}