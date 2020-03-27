#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(int nArgc, char** pArgv) {
	//The first line in the input contains the number of test cases
	int nNumberOfTestCases;
	cin >> nNumberOfTestCases;

	while (nNumberOfTestCases-- > 0) {
		//Read the number, which has to be checked whether it is fascinating or
		//not
		int nNumber;
		cin >> nNumber;

		//A fascinating number is a number, which when multiplied by 2 and 3,
		//and when the results are concatenated with the original number, then
		//it results in all digits from 1 to 9 present exactly once.
		
		bool bIsFascinatingNumber = true;
		int n2Mult = nNumber * 2;
		int n3Mult = nNumber * 3;

		//Now we need to concatenate it with the original number
		stringstream ssConcatenatedNumber; 
		ssConcatenatedNumber << nNumber << n2Mult << n3Mult;
		string strConcatenatedNumber = ssConcatenatedNumber.str();
		size_t nSize = strConcatenatedNumber.size();

		//Now we need to check that the occurance of the number only happens
		//once
		//Create an array of size 10
		int* pArray = new int[9];
		memset(pArray, 0, 9);
		//each element of this array will contain the occurance of each number
		//so element at 0th index will store the number of times 1 was found
		//element at 1st index will store the number of times 2 was found

		for (size_t i = 0; i < nSize; ++i) {
			int nChar = strConcatenatedNumber.at(i) - '0';
			if (nChar == 0) {
				bIsFascinatingNumber = false;
				break;
			}
			pArray[nChar - 1] += 1;
			
			if (pArray[nChar - 1] > 1) {
				bIsFascinatingNumber = false;
				break;
			}
		}

		cout << bIsFascinatingNumber << endl;
		delete[] pArray;
		pArray = nullptr;
	}
	return 0;
}