#include <iostream>

using namespace std;

template <class T> class Node {
public:
	Node(const T& oData, Node<T>* pLeft = nullptr, Node<T>* pRight = nullptr) :
		m_oData(oData), m_nCount(1), m_pLeft(pLeft), m_pRight(pRight) {

	}
	~Node() {
		SetRight(nullptr);
		SetLeft(nullptr);
		SetCount(0);
	}

	void		SetData(const T& oData)		{ m_oData = oData; };
	void		SetCount(int nCount)		{ m_nCount = nCount; };
	int			IncrementCount()			{ ++m_nCount; return m_nCount; };
	void		SetLeft(Node<T>* pNode)		{ m_pLeft = pNode; };
	void		SetRight(Node<T>* pNode)	{ m_pRight = pNode; };

	T			GetData() const				{ return m_oData; };
	int			GetCount() const			{ return m_nCount; };
	Node<T>*	GetLeft() const				{ return m_pLeft; };
	Node<T>*	GetRight() const			{ return m_pRight; };
private:
	T			m_oData;
	int			m_nCount;
	Node<T>*	m_pLeft = nullptr;
	Node<T>*	m_pRight = nullptr;
};

template <class T> class BinaryTree {
public:
	BinaryTree() : m_pRoot(nullptr) {};
	~BinaryTree();

	Node<T>*	Insert(const T& oData);
	void		EmptyTree();
	Node<T>*	SetRoot(Node<T>* pNode) { 
		Node<T>* pExistingRoot = GetRoot();
		m_pRoot = pNode;
		return pExistingRoot;
	};
	Node<T>*	GetRoot() const { return m_pRoot; };
	
	Node<T>*	FindFirstUnique() const;

	//traversal functions
	Node<T>*	Inorder(Node<T>* pNode) const;

	//overloaded operators
	//insertion operator
	template <class T1>
	friend BinaryTree<T1>& operator >> (istream& in, BinaryTree<T1>& oTree);
private:
	void		ClearTree(Node<T>* pNode);
	void		_FindFirstUnique(Node<T>* pNode, Node<T>*& pFoundNode) const;
	Node<T>*	m_pRoot = nullptr;
};

template <class T>
BinaryTree<T>::~BinaryTree() {
	EmptyTree();
}

template <class T>
void BinaryTree<T>::EmptyTree() {
	ClearTree(m_pRoot);
	SetRoot(nullptr);
}

template <class T>
void BinaryTree<T>::ClearTree(Node<T>* pNode) {
	if (nullptr == pNode) {
		return;
	}

	ClearTree(pNode->GetLeft());
	ClearTree(pNode->GetRight());

	delete pNode;
	pNode = nullptr;
}

template <class T1>
BinaryTree<T1>& operator >> (istream& in, BinaryTree<T1>& oTree) {
	T1 oData;
	in >> oData;
	oTree.Insert(oData);
	return oTree;
}

template <class T>
Node<T>* BinaryTree<T>::Insert(const T& oData) {
	Node<T>* pNode = nullptr;
	if (m_pRoot == nullptr) {
		pNode = new Node<T>(oData);
		SetRoot(pNode);
	}
	else {
		Node<T>* pParent = nullptr;
		Node<T>* pCurrent = m_pRoot;

		for (;;) {
			pParent = pCurrent;
			if (oData == pCurrent->GetData()) {
				//oData and pCurrent->GetData() are same
				//so increment the count in pCurrent
				pParent->IncrementCount();
				pNode = pParent;
				break;
			}
			else if (oData < pCurrent->GetData()) {
				//go left
				pCurrent = pCurrent->GetLeft();
				if (!pCurrent) {
					//this is the palce
					pParent->SetLeft(new Node<T>(oData));
					break;
				}
			}
			else if (oData > pCurrent->GetData()) {
				//go right
				pCurrent = pCurrent->GetRight();
				if (!pCurrent) {
					//this is the place
					pParent->SetRight(new Node<T>(oData));
					break;
				}
			}
			else {
				//should not come here.
				break;
			}
		}//for (;;) 
	}

	return pNode;
}

template <class T>
void BinaryTree<T>::_FindFirstUnique(Node<T>* pNode, Node<T>*& pFoundNode) const {
	//This function does an inorder traversal (recrusively) and finds node
	//whose Count is one.
	if (pNode == nullptr) {
		return;
	}

	if (pNode->GetCount() == 1) {
		pFoundNode = pNode;
		return;
	}
	_FindFirstUnique(pNode->GetLeft(), pFoundNode);
	_FindFirstUnique(pNode->GetRight(), pFoundNode);
}

template <class T>
Node<T>* BinaryTree<T>::FindFirstUnique() const {
	//This function does an inorder traversal (recrusively) and finds node
	//whose Count is one.
	Node<T>* pNode;
	_FindFirstUnique(m_pRoot, pNode);
	return pNode;
}

template <class T>
Node<T>* BinaryTree<T>::Inorder(Node<T>* pNode) const {
	if (pNode == nullptr) {
		return nullptr;
	}

	//first iterate the left tree and then the right tree
	Inorder(pNode->GetLeft());
	
}

//Given an array which contains all elements occurring k times, but one occurs 
//only once. Find that unique element.
int main(int nArgc, char** pArgv) {
	//The first line in the input contains the number of test cases
	int nNumberOfTestCases;
	cin >> nNumberOfTestCases;

	while (nNumberOfTestCases-- > 0) {
		//The next line contains the size of the array
		int64_t nSize;
		cin >> nSize;

		int nNumberOfTimes;
		cin >> nNumberOfTimes;

		//Now read the array data
		BinaryTree<int> oTree;
		for (int i = 0; i < nSize; ++i) {
			cin >> oTree;
		}

		Node<int>* pNode = oTree.FindFirstUnique();
		cout << (pNode == nullptr ? -1 : pNode->GetData()) << endl;
	}

	return 0;
}