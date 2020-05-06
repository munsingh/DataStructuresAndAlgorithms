#include <iostream>
#include <string>
using namespace std;

//Given a string S consisting only '0's and '1's,  print the last index of the 
//'1' present in it.
int main(int nArgc, char** pArgv) {
	//The first line in the input contains the number of test cases
	int nNumberOfTestCases;
	cin >> nNumberOfTestCases;

	while (nNumberOfTestCases-- > 0) {
		//The next line contains the string
		string strString;
		cin >> strString;
		int i = static_cast<int>(strString.size()) - 1;
		bool bFound(false);
		for (; i >= 0; --i) {
			if (strString[i] == '1') {
				bFound = true;
				break;
			}
		}
		
		cout << (bFound ? i : -1) << endl;
	}

	return 0;
}