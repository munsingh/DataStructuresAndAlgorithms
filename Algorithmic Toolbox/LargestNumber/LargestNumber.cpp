#include <iostream>
#include <string>
#include <sstream>

template <class T> class Node {
	public:
				Node(const T& oData, Node<T>* pNext = nullptr)
					:m_oData(oData), m_pNext(pNext) {}
				Node(const Node<T>& oNode)
					: Node(oNode.GetData(), oNode.GetNext()){};
				Node(const Node<T>* pNode)
					: Node(pNode->GetData(), pNode->GetNext()) {};
		virtual ~Node() { SetNext(); };

		//assignment operator
		Node<T>& operator = (const Node<T>& oNode) {
			if (this != &oNode) {
				this->SetData(oNode.GetData());
				this->SetNext(oNode.GetNext());
			}

			return *this;
		}

		const T&		GetData() const { return m_oData; };
		const Node<T>*	GetNext() const { return m_pNext; };
		Node<T>*		GetNext() { return m_pNext; };

		void SetData(const T& oData) { m_oData = oData; };
		void SetNext(Node<T>* pNext = nullptr) { m_pNext = pNext; };

		friend std::ostream& operator << (std::ostream& out, const Node<T>* pNode) {
			//Here we print the data inside the Node
			out << pNode->GetData();
			return out;
		};

	private:
		T		m_oData;
		Node<T> *m_pNext = nullptr;
};

template <class T> class List {
	public:
				List(bool bSorted = true, bool bAscending = true)
					: m_pHead(nullptr), m_bSorted(bSorted), m_bAscending( bAscending ) {};
				List(const List<T>& oList);
		virtual ~List();
		List<T>& operator = (const List<T>& oList);

		//member functions
		Node<T>*	AddHead(const T& oData);
		Node<T>*	AddNode(const T& oData);
		Node<T>*	GetHead() const { return m_pHead; };
		virtual bool	Compare(const T& oData1, const T& oData2);

		//Overloaded operators
		friend std::ostream& operator << (std::ostream& out, const List<T>& oList) {
			Node<T>* pCurr = oList.GetHead();

			while (nullptr != pCurr) {
				out << pCurr;
				pCurr = pCurr->GetNext();
			}

			return out;
		};

		friend std::istream& operator >> (std::istream& in, List<T>& oList) {
			T oData;
			in >> oData;
			oData >> oList;
			return in;
		};

		friend List<T>& operator >> (const T& oData, List<T>& oList) {
			oList.AddNode(oData);
			return oList;
		};

	protected:
		Node<T>*	SetHead(Node<T>* pNode) { m_pHead = pNode; return GetHead(); };
		void		CopyList(const List<T>& oList);
		void		ClearList();

		Node<T>*	m_pHead = nullptr;
		bool		m_bSorted = true;
		bool		m_bAscending = true;
};

template <class T> List<T>::List(const List<T>& oList) {
	CopyList( oList);
}

template <class T> List<T>::~List() {
	ClearList();
}

template <class T> Node<T>* List<T>::AddHead(const T& oData) {
	//Since this explictly adds a node irrespective of sorted or not.
	//So using this function makes the list unsorted
	m_bSorted = false;
	SetHead(new Node<T>(oData, GetHead()));
	return GetHead();
}

template <class T> Node<T>* List<T>::AddNode(const T& oData) {
	//Add a new Node, depending on whether the node is to be sorted or
	//not
	//if not sorted then AddNode adds a new Head, else it iterates the list
	//and adds the node at an appropriate place.
	Node<T>* pNewNode = nullptr;
	
	if (m_bSorted) {
		Node<T>* pCurr = GetHead();
		Node<T>* pPrev = nullptr;

		while (pCurr && this->Compare( pCurr->GetData(), oData ) ) {
			pPrev = pCurr;
			pCurr = pCurr->GetNext();
		}

		//Now we have found the Node (pCurr) whose data is more than oData
		//so the new node has to be befor this, which is after pPrev
		if (pPrev == nullptr) {
			SetHead(new Node<T>(oData, pCurr));
			return GetHead();//node added
		}
		else {
			pPrev->SetNext(new Node<T>(oData, pPrev->GetNext()));
			return pPrev->GetNext();//node added
		}
	}
	else {
		pNewNode = new Node<T>(oData, GetHead());
		SetHead(pNewNode);
	}

	return pNewNode;
}

template <class T> bool List<T>::Compare(const T& oData1, const T& oData2) {
	return m_bAscending ? oData1 < oData2 : oData1 > oData2;
}

/*
 * Iterate over the list one by one and delete the nodes, untill the end of
 * list is reached
*/
template <class T> void List<T>::ClearList() {
	Node<T> *pNode = nullptr;

	while (nullptr != (pNode = GetHead())) {
		SetHead(GetHead()->GetNext());
		delete pNode;
	}
}

template <class T> void List<T>::CopyList(const List<T>& oList) {
	if (*this != oList) {
		ClearList();

		Node<T>* pSourceNode = oList.GetHead();
		Node<T>* pPrev = nullptr;
		Node<T>* pNew = nullptr;

		while (nullptr != pSourceNode) {
			pNew = new Node<T>(pSourceNode->GetData());
			if (nullptr == GetHead()) {
				SetHead(pNew);
			}
			else {
				pPrev->SetNext(pNew);
			}

			pPrev = pNew;
			pSourceNode = pSourceNode->GetNext();
		}
	}
}

template <class T> List<T>& List<T>::operator=(const List<T>& oList) {
	if (*this != oList) {
		
		CopyList(oList);
	}

	return *this;
}

class CustomList : public List<int> {
	public:
				CustomList() : List(true, false) {};
		virtual ~CustomList() {};
		bool	Compare(const int& oData1, const int& oData2);
};

bool CustomList::Compare(const int& oData1, const int& oData2) {
	//We create two stringstrams using oData1 and oData2
	std::stringstream oStream1, oStream2;
	oStream1 << oData1 << oData2;
	oStream2 << oData2 << oData1;

	if (oStream1.str() > oStream2.str())
		return true;
	else
		return false;
}

int main(int nArgv, char** pArgc) {
	int nNumberOfNumbers;
	std::cin >> nNumberOfNumbers;
	
	//create a sorted list
	CustomList oList;
	for (int i = 0; i < nNumberOfNumbers; ++i) {
		std::cin >> oList;
	}

	std::cout << oList;

	return 0;
}