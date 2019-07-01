#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

int GetEditDistance(std::string& strRow, std::string& strColumn) {
	//We create a table where number of rows = size of strRow + 1
	//and number of columns = size of strColumn + 1
	std::vector<std::vector<int>> vecTables(strRow.length() + 1, 
											std::vector<int>( 
												strColumn.length() + 1));

	//fill up the first row and column with increasing numbers from 0 to the
	//length
	for (int nRow = 0; nRow < strRow.length() + 1; nRow++) {
		vecTables[nRow][0] = nRow;
	}

	for (int nColumn = 0; nColumn < strColumn.length() + 1; nColumn++) {
		vecTables[0][nColumn] = nColumn;
	}

	//We use the Wagner–Fischer algorithm algorithm to compute the Edit
	//Distance between two strings.

	//In Computational Linguistics and Computer Science, edit distance is a way
	//of quantifying how dissimilar two strings (e.g. words) are to one another
	//by counting the minimum number of operations required to transform one
	//string into the other. Edit Distance find applications in NLP (Natural 
	//Language Processing, where automatic spelling corrections for a mis-
	//spelled word by selecting words from a dictionary that have a low
	//distance to the word in question.
	//In BioInformatics, it can be used to quantify the similarity of DNA
	//sequences, which can be viewed as strings ot the letters A, C, G and T.
	//So the formula used here is:

	//vecTables[nRow][nColumn] = minimum of one of the following:
	//							1. vecTable[nRow, nColumn -1] + 1 , or
	//							2. vecTables[nRow -1, nColumn] + 1, or
	//if strRow[nRow] != strColumn[nColumn], then
	//						    3. vecTables[nRow-1, nColumn-1] + 1, or
	//if strRow[nRow] == strColumn[nColumn]. then
	//							3. vecTables[nRow-1, nColumn-1]

	//The value in vecTables[nRow][nColumn] at the end is the edit distance
	//to be calculated
	for (int nColumn = 1; nColumn < strColumn.length() + 1; nColumn++) {
		for (int nRow = 1; nRow < strRow.length() + 1; nRow++) {
			int nInsertion = vecTables[nRow][nColumn - 1] + 1;
			int nDeletion = vecTables[nRow - 1][nColumn] + 1;
			int nMatch = vecTables[nRow - 1][nColumn - 1];
			int nMismatch = vecTables[nRow - 1][nColumn - 1] + 1;

			if (strRow[nRow] == strColumn[nColumn]) {
				//match
				vecTables[nRow][nColumn] = std::min({ nInsertion, nDeletion, nMatch });
			}
			else {
				vecTables[nRow][nColumn] = std::min({ nInsertion, nDeletion, nMismatch });
			}
		}
	}

	return vecTables[strRow.length()][strColumn.length()];
}

int main(int /*nArgv*/, char** /*pArgc*/) {
	//read two strings whose edit distance needs to be found
	std::string strRow, strColumn;
	std::cin >> strRow >> strColumn;

	std::cout << GetEditDistance(strRow, strColumn);
	return 0;
}