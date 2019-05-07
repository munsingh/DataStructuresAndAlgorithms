#include <iostream>
#include <random>

template <class T> class Node {
	public:
		Node(const T& oData, Node<T>* pNext = nullptr) :
			m_oData(oData), m_pNext(pNext) {};
		Node(const Node<T>& oNode) {
			*this = oNode;
		};
		Node(const Node<T>* pNode) : Node( *pNode ) {};
		Node() : m_pNext(nullptr) {};

		~Node() { m_pNext = nullptr; };

		Node& operator = (const Node& oNode) {
			if (*this != oNode) {
				this->SetData(oNode.GetData());
				this->SetNode(oNode.GetNext());
			}

			return *this;
		}

		void				SetNext(Node<T>* pNext) { m_pNext = pNext; };
		void				SetData(const T& oData) { m_oData = oData; };
		const Node<T>*		GetNext() const			{ return m_pNext; };
		Node<T>*			GetNext()				{ return m_pNext; };
		const T&			GetData() const			{ return m_oData; };
		T&					GetData()				{ return m_oData; };

		//overloaded insertion operator
		friend std::istream* operator >> (std::istream& in, Node<T>& oNode) {
			in >> oNode.m_oData;
			in >> oNode.m_pNext;
		}
	private:
		T			m_oData;
		Node<T>*	m_pNext = nullptr;
};

template <class T> class List {
	public:
				List(bool bSorted = true, bool bAscending = true) :
					m_bSorted(bSorted), m_bAscending(bAscending), m_pHead(nullptr) {};
		virtual ~List() { ClearList(); };

		void			SetHead(Node<T>* pHead) { m_pHead = pHead; };
		const Node<T>*	GetHead() const			{ return m_pHead; };
		Node<T>*		GetHead()				{ return m_pHead; };
		Node<T>*		AddNode(const T& oData);

		void			ClearList();
		Node<T>*		AddHead(Node<T>* pNode);
		Node<T>*		DeleteHead();
		virtual bool	Compare(const T& oData1, const T& oData2);

		//overloaded insertion operator
		friend std::istream& operator >> (std::istream& in, List<T>& oList) {
			T oData;
			in >> oData;
			oList.AddNode(oData);
		};

		friend List<T>& operator >> (T& oData, List<T>& oList) {
			oList.AddNode(oData);
			return oList;
		};
	private:
		bool		m_bSorted		= true;
		bool		m_bAscending	= true;
		Node<T>*	m_pHead			= nullptr;
};

template <class T> bool List<T>::Compare(const T& oData1, const T& oData2) {
	return m_bAscending ? oData1 < oData2 : oData1 > oData2;
}

template <class T> Node<T>* List<T>::AddHead(Node<T>* pNode) {
	pNode->SetNext(GetHead());
	SetHead(pNode);
	return GetHead();
}

template <class T> Node<T>*	List<T>::AddNode(const T& oData) {
	Node<T>* pNewNode = new Node<T>(oData);
	if (GetHead()) {
		if (m_bSorted) {
			//Decide adding based on Sorting Order
			Node<T>* pCurr = GetHead();
			Node<T>* pPrev = nullptr;
			while (pCurr && this->Compare(pCurr->GetData(), oData)) {
				pPrev = pCurr;
				pCurr = pCurr->GetNext();
			}

			//Need to add between pPrev and pCurr
			if (pPrev) {
				pNewNode->SetNext(pPrev->GetNext());
				pPrev->SetNext(pNewNode);
			}
			else {
				//pPrev is null, this means the list had only one entry
				pNewNode->SetNext(pCurr);
				SetHead(pNewNode);
			}
		}
		else {
			//No sorting, add heads
			AddHead(pNewNode);
		}
	}
	else {
		//empty list
		SetHead(pNewNode);
	}

	return pNewNode;
}
template <class T> Node<T>* List<T>::DeleteHead() {
	//delete the current head and return the new head
	Node<T>* pCurrHead = GetHead();
	if (pCurrHead) {
		SetHead(pCurrHead->GetNext());
		delete pCurrHead;
	}

	return GetHead();
}

template <class T> void List<T>::ClearList() {
	while (GetHead()) {
		DeleteHead();
	}
}

template <class T>
int LinearSearchIterative(List<T>& oList, int nNumberToSearch) {
	int nIndex = -1;

	Node<T>* pCurr = oList.GetHead();
	while (pCurr && nNumberToSearch != pCurr->GetData()) {
		pCurr = pCurr->GetNext();
		++nIndex;
	}

	bool bFound = pCurr ? true : false;

	return bFound ? nIndex : -1;
}

int main(int /*nAarg*/, char** /*pArgc*/) {
	//There are two ways to do linear search.
	//Recursive and Iterative.
	
	//Generate random numbers between 1 and 100 and save it in the list
	List<int> oList;
	
	std::mt19937 rng; //random number generator
	rng.seed();
	std::uniform_int_distribution<int> dist100(1, 100);
	int nNumber = -1;
	for (size_t i = 0; i < 100; ++i) {
		nNumber = dist100(rng);
		nNumber >> oList;
	}

	int nIndex = LinearSearchIterative(oList, nNumber);
	nIndex == -1 ? std::cout << "Not found" : std::cout << "Found " << nNumber << " at index: " << nIndex;
	return 0;
}