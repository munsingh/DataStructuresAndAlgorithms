#include <algorithm>
#include <iostream>
#include <vector>

template <class T> class Node {
	public:
		//constructors
				Node(const T& oData, Node<T>* pNext = nullptr)
					:m_oData(oData), m_pNext(pNext) {};
				Node(const T* pData, Node<T>* pNext = nullptr)
					:Node(*pData, pNext) {};

				//copy constructor
				Node(const Node<T>& oNode) {
					*this = oNode;
				};

				//assignment operatpr
				Node<T>& operator = (const Node<T>& oNode) {
					if (this != &oNode) {
						SetData( oNode.GetData() );
						SetNext(oNode.GetNext());
					}
				};
		virtual ~Node() {
			m_pNext = nullptr;
		};

		const T&		GetData() const { return m_oData; };
		T&				GetData() { return m_oData; };
		const Node<T>*	GetNext() const { return m_pNext; };
		Node<T>*		GetNext() { return m_pNext; };

		void			SetData(const T& oData)				{ m_oData = oData; };
		void			SetNext(Node<T>* pNext = nullptr)	{ m_pNext = pNext; };
	private:
		T			m_oData;
		Node<T>*	m_pNext = nullptr;
};

template <class T> class List {
	public:
				List(bool bSorted = true, bool bAscending = false) :
					m_bSorted(bSorted),
					m_bAscending(bAscending),
					m_pHead(nullptr){};
		virtual ~List() { ClearList(); };

		Node<T>*		AddNode(const T& oData);
		const Node<T>*	GetHead() const				{ return m_pHead; };
		Node<T>*		GetHead()					{ return m_pHead; };
		void			SetHead(Node<T>* pNode)		{ m_pHead = pNode; };
		Node<T>*		DeleteHead();
		void			ClearList();

		virtual bool	Compare(const T& oData1, const T& oData2);

		//overloaded insertion operator
		friend std::istream& operator >> (std::istream& in, List<T>& oList) {
			T oData;
			in >> oData;
			oData >> oList;
			return in;
		}

		friend List<T>& operator >> (const T& oData, List<T>& oList) {
			oList.AddNode(oData);
			return oList;
		}

	private:
		bool		m_bSorted = true;
		bool		m_bAscending = false;
		Node<T>*	m_pHead;
};

template <class T> Node<T>* List<T>::AddNode(const T& oData) {
	Node<T>* pNewNode = new Node<T>(oData);

	Node<T>* pCurr = GetHead();
	if (nullptr == pCurr) {
		//first entry, it becomes the head automatically
		SetHead(pNewNode);
	}
	else {
		if (m_bSorted) {
			//then add node depedending on the comparison
			Node<T>* pPrev = nullptr;

			while (pCurr && this->Compare(pCurr->GetData(), oData)) {
				pPrev = pCurr;
				pCurr = pCurr->GetNext();
			}

			//handle cases where there is only one entry
			//we have to add he node between pPrev and pCurr
			if (pPrev == nullptr) {
				//only one entry
				pNewNode->SetNext(pCurr);
				SetHead(pNewNode);
			}
			else {
				pNewNode->SetNext(pPrev->GetNext());
				pPrev->SetNext(pNewNode);
			}
		}
		else {
			//Not sorted, then it becomes the head
			//In O(1) time add nodes to the list
			pNewNode->SetNext(GetHead());
			SetHead(pNewNode);
		}
	}

	return pNewNode;
}
template <class T> bool List<T>::Compare(const T& oData1, const T& oData2) {
	//if ascending order, then return false if oData1 is smaller than oData2, otherwise true
	//if descending order, then return true if oData1 is greater than oData2. otherwise false
	return m_bAscending ? oData1 < oData2 : oData1 > oData2;
}

template <class T> Node<T>* List<T>::DeleteHead() {
	Node<T>* pCurrHead = GetHead();
	SetHead(pCurrHead->GetNext());
	delete pCurrHead;
	return GetHead();
}

template <class T> void List<T>::ClearList() {
	Node<T>* pNode = GetHead();
	while (pNode) {
		pNode = DeleteHead();
	}
}


long long max_dot_product(List<long long>& oProfitList, List<long long>& oAverageClicksList) {
	long long llResult = 0;
	
	//for maximum revenue
	//we sum the product of head of both the lists
	Node<long long>* pProfitHead = oProfitList.GetHead();
	Node<long long>* pAverageClicksHead = oAverageClicksList.GetHead();

	while (pProfitHead) {
		llResult += (pProfitHead->GetData() * pAverageClicksHead->GetData());
		pProfitHead = oProfitList.DeleteHead();
		pAverageClicksHead = oAverageClicksList.DeleteHead();
	}

	return llResult;
}

int main() {
	size_t nNumberOfAds;		//Get the number of ads
	std::cin >> nNumberOfAds;
	
	List< long long > oProfitList, oAverageClicksList;

	for (size_t i = 0; i < nNumberOfAds; i++)
		std::cin >> oProfitList;

	for (size_t i = 0; i < nNumberOfAds; i++)
		std::cin >> oAverageClicksList;

	std::cout << max_dot_product(oProfitList, oAverageClicksList) << std::endl;

	return 0;
}
