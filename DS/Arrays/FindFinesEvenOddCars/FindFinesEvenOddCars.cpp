#include <iostream>

using namespace std;

int main(int nArgc, char** pArgv) {
	//The first line in the input contains the number of test cases
	size_t nNumberOfTestCases;
	cin >> nNumberOfTestCases;

	while (nNumberOfTestCases-- > 0) {
		//The next line contains the size of the array
		int64_t nSize;
		cin >> nSize;
		int nDate;
		cin >> nDate;

		//Now read the array data
		int* pCarNumbers = new int[nSize];
		for (int64_t i = 0; i < nSize; ++i) {
			cin >> pCarNumbers[i];
		}

		int* pPenalties = new int[nSize];
		for (int64_t i = 0; i < nSize; ++i) {
			cin >> pPenalties[i];
		}

		//We collect fine depending on the date
		//so if Date is even, then odd number cars are banned so they need to
		//be fined and vice-versa
		bool bIsDateEven = nDate % 2 == 0 ? true : false;

		int nPenalty(0);
		for (int i = 0; i < nSize; ++i) {
			//iterate the car array and depending on the date, fine the car
			if (bIsDateEven) {
				//odd number cars to be fined
				if (pCarNumbers[i] % 2 != 0) {
					//odd car, so fine it
					nPenalty += pPenalties[i];
				}
			}
			else {
				//even number cars to be fined
				if (pCarNumbers[i] % 2 == 0) {
					//even cars so fine it
					nPenalty += pPenalties[i];
				}
			}
		}

		cout << nPenalty << " " << endl;
		delete[] pPenalties;
		pPenalties = nullptr;

		delete[] pCarNumbers;
		pCarNumbers = nullptr;
	}
	return 0;
}