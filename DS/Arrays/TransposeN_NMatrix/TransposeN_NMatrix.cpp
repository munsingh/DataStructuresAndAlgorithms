#include <iostream>

using namespace std;

//Given an unsorted array Arr[] of N integers and a Key which is present in 
//this array. You need to write a program to find the start index
//(index where the element is first found from left in the array) and end 
//index (index where the element is first found from right in the array).
int main(int nArgc, char** pArgv) {
	//The first line in the input contains the number of test cases
	int nNumberOfTestCases;
	cin >> nNumberOfTestCases;

	while (nNumberOfTestCases-- > 0) {
		//The next line contains the size of the array
		int nSize;
		cin >> nSize;

		//First create the 2d Array
		int** pArray = new int*[nSize];
		for (size_t i = 0; i < nSize; ++i) {
			pArray[i] = new int[nSize];
		}

		//Now read in the elements

		//iterate the array
		for (int nRow = 0; nRow < nSize; ++nRow) {
			for (int nCol = 0; nCol < nSize; ++nCol) {
				cin >> pArray[nRow][nCol];
			}
		}

		//Transpose of a matrix for example
		//1 2
		//3 4 
		//is
		//1 3
		//2 4
		//i.e., the row and column entry is swapped with
		
		//display the matrix
		for (int nRow = 0; nRow < nSize; ++nRow) {
			for (int nCol = 0; nCol < nSize; ++nCol) {
				cout << pArray[nCol][nRow] << " ";
			}
		}

		cout << endl;
		for (size_t i = 0; i < nSize; ++i) {
			delete[] pArray[i];
		}

		delete[] pArray;
	}
	return 0;
}