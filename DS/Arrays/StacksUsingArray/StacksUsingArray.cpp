#include <iostream>
using namespace std;

class MyStack {
public:
	MyStack() :m_nTop(-1) {}
	~MyStack() { m_nTop = -1; }
	int		Pop();
	void	Push(int nElement);
private:
	int m_nTop;
	int m_arr[1000];
};

int MyStack::Pop() {
	//In pop we read the top most element and update m_nTop to point to the
	//index, which points to the top
	int nElement = -1;
	if (m_nTop == -1) {
		//empty
		return nElement;
	}
	else {
		m_nTop++;
		nElement = m_arr[m_nTop];;
		if (m_nTop == 999) {
			//no more elements to pop, stack is empty
			m_nTop = -1;
		}
	}

	return nElement;
}

void MyStack::Push(int nElement) {
	if (m_nTop == -1) {
		//stack is empty
		m_nTop = 1000 - 1;
		m_arr[m_nTop--] = nElement;
	}
	else {
		m_arr[m_nTop--] = nElement;
	}
}

int main(int nArgc, char** pArgv) {
	int nNumberOfTestCases;
	cin >> nNumberOfTestCases;

	while (nNumberOfTestCases-- > 0) {
		//The next line contains the number of queries

		int nQueries;
		cin >> nQueries;
		MyStack oStack;
		while (nQueries--) {
			int nQueryType;
			cin >> nQueryType;
			if (nQueryType == 1) {
				//push the next element
				int nElement;
				cin >> nElement;
				oStack.Push(nElement);
			}
			else if (nQueryType == 2) {
				cout << oStack.Pop() << " ";
			}
		}
		
		cout << endl;
	}
	return 0;
}