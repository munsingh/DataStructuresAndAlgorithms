#include <vector>
#include <random>
#include <iostream>
#include <time.h>

template <class T> class Node {
	public:
		Node(const T& oData, Node<T>* pNext= nullptr) : m_oData(oData), m_pNext(pNext) {};
		Node(const Node& oNode) {
			*this = oNode;
		};
		Node(const Node* pNext) : Node(*pNext) {};
		Node();
		~Node() { m_pNext = nullptr; };

		Node<T>& operator = (const Node& oNode) {
			if (*this != oNode) {
				this->SetData(oNode.GetData());
				this->SetNext(oNode.GetNext());
			}
		};

		void			SetNext(Node* pNext)	{ m_pNext = pNext; };
		Node<T>*		GetNext()				{ return m_pNext; };
		const Node<T>*	GetNext() const			{ return m_pNext; };

		void			SetData(const T& oData) { m_oData = oData; };
		T&				GetData()				{ return m_oData; };
		const T&		GetData() const			{ return m_oData; };

		friend std::istream& operator >> (std::istream& in, Node<T>& oNode) {
			in >> m_oData;
			return in;
		};

		friend std::ostream& operator << (std::ostream& out, Node<T>& oNode) {
			out << oNode.GetData();
			return out;
		};
	private:
		T			m_oData;
		Node<T>*	m_pNext = nullptr;
};

template <class T> class List {
	public:
				List(bool bSorted = true, bool bAscending = true)
					: m_bSorted(bSorted), m_bAscending(bAscending) {};
		virtual ~List() { ClearList(); };												   
		virtual bool	Compare(const T& oData1, const T& oData2);

		Node<T>*		GetTail() {
			return GetPrev(nullptr);
		};

		const Node<T>*		GetTail() const {
			return GetPrev(nullptr);
		};
		Node<T>*		GetMid(const Node<T>* pLow, const Node<T>* pHigh);
		Node<T>*		GetPrev(const Node<T>* pNode);
		int				GetIndex(const Node<T>* pNode); 
		Node<T>*		GetHead() { return m_pHead; };
		void			SetHead(Node<T>* pNode) { m_pHead = pNode; };
		Node<T>*		AddNode(const T& oData);
		
		Node<T>* DeleteHead() {
			Node<T>* pCurrHead = GetHead();
			SetHead(pCurrHead->GetNext());
			delete pCurrHead;
			return GetHead();
		};

		void ClearList() {
			while (GetHead())
				DeleteHead();
		};

		void AddHead(Node<T>* pNode) {
			pNode->SetNext(GetHead());
			SetHead(pNode);
		};

		friend std::istream& operator >> (std::istream& in, List<T>& oList) {
			T oData;
			in >> oData;
			oList.AddNode(oData);
			return in;
		};

		friend List<T>& operator >> (T& oData, List<T>& oList) {
			oList.AddNode(oData);
			return oList;
		};

		friend std::ostream& operator << (std::ostream& out, List<T>& oList) {
			Node<T>* pCurr = oList.GetHead();
			while (pCurr) {
				out << *pCurr;
				pCurr = pCurr->GetNext();
				if (pCurr) {
					out << " ";
				}
			}
			out << "\n";
			return out;
		};

	private:
		bool		m_bSorted = true;
		bool		m_bAscending = true;
		Node<T>*	m_pHead = nullptr;
};

template <class T> bool List<T>::Compare(const T& oData1, const T& oData2) {
	return m_bAscending ? oData1 < oData2 : oData1 > oData2;
};

template <class T> int List<T>::GetIndex(const Node<T>* pNode) {
	int nIndex = 0;
	Node<T>* pCurr = GetHead();

	while (pCurr && pCurr != pNode) {
		pCurr = pCurr->GetNext();
		++nIndex;
	}

	if (pCurr == nullptr) {
		//not found
		return -1;
	}
	else 
		return nIndex;
}

template <class T> Node<T>* List<T>::GetMid(const Node<T>* pLow, const Node<T>* pHigh) {

	if (nullptr == pLow)
		return nullptr;
	if (pLow == pHigh)
		return const_cast< Node<T>*>(pLow);
	//we iterate the list till the node pNode
	//from there we start two pointers pFast and pSlow
	//pSlow moves one node at a time and pFast moves two nodes at a time
	//When pFast reaches pHigh, the node being pointed by pSlow is the middle of pLow and pHigh
	Node<T>* pSlow = GetHead();
	while (pSlow && pSlow != pLow) {
		pSlow = pSlow->GetNext();
	}

	//out of the while loop, two reasons we found the pSlow or not
	if (nullptr == pSlow)
		return nullptr;

	Node<T>* pFast = pSlow;
	while (pFast && pFast != pHigh) {
		pSlow = pSlow->GetNext();
		pFast = pFast->GetNext();
		if (pHigh == pFast)
			break;

		pFast = pFast->GetNext();
	}

	return pSlow;
}

template <class T> Node<T>* List<T>::GetPrev(const Node<T>* pNode) {
	//iterate the list till the point pNode, the previous node being tracked 
	//is to be returned
	Node<T>* pCurr = GetHead();
	Node<T>* pPrev = nullptr;

	while (pCurr && pCurr != pNode) {
		pPrev = pCurr;
		pCurr = pCurr->GetNext();
	}

	return pPrev;
}

template <class T> Node<T>* List<T>::AddNode(const T& oData) {
	Node<T>* pNewNode	= new Node<T>(oData);
	Node<T>* pCurr = GetHead();
	if (pCurr) {
		//Node exists
		if (m_bSorted) {
			Node<T>* pPrev = nullptr;

			while (pCurr && this->Compare(pCurr->GetData(), oData)) {
				pPrev = pCurr;
				pCurr = pCurr->GetNext();
			}

			//add node between pPrev and pCurr
			if (pPrev) {
				pNewNode->SetNext(pPrev->GetNext());
				pPrev->SetNext(pNewNode);
			}
			else {
				AddHead(pNewNode);
			}
		}
		else {
			AddHead(pNewNode);
		}
	}
	else {
		//First node
		AddHead(pNewNode);
	}

	return pNewNode;
}

template <class T> int BinarySearchRecursive(std::vector<T>& vecNumbers, size_t nLow, size_t nHigh, const T& oData) {
	if (nHigh >= nLow) {
		size_t nMid = nLow + (nHigh - nLow) / 2;
		if (vecNumbers[nMid] == oData)
			return nMid;
		else if (vecNumbers[nMid] < oData) {
			return BinarySearchRecursive(vecNumbers, nMid + 1, nHigh, oData);
		}
		else if (vecNumbers[nMid] > oData) {
			return BinarySearchRecursive(vecNumbers, nLow, nMid - 1, oData);
		}
		else {
			return -1;//should not come here
		}
	}
	return -1;
}

template <class T> int BinarySearchIterative(std::vector<T>& vecNumbers, size_t nLow, size_t nHigh, const T& oData) {
	while (nLow <= nHigh) {
		int nMid = nLow + (nHigh - nLow) / 2;
		if (vecNumbers[nMid] == oData) {
			return nMid;
		}
		else if (vecNumbers[nMid] < oData) {
			//look into the 2nd half
			nLow = nMid + 1;
		}
		else if (vecNumbers[nMid] > oData) {
			nHigh = nMid - 1;
		}
	}

	return -1; //not found
}

template <class T> int BinarySearch(std::vector<T>& vecNumbers, const T& oData, bool bRecursive = true) {
	return bRecursive ? BinarySearchRecursive(vecNumbers, 0, vecNumbers.size() - 1 , oData) : BinarySearchIterative(vecNumbers, 0, vecNumbers.size() - 1, oData);
}

int main(int /*nArgc*/, char** /*pArgv*/) {
	int nCount = 0;
	std::cin >> nCount;

	//List<int> oList;
	std::vector<int> vecNumbers(nCount);

	//Binary search works on a sorted array
	//the Approach is to divide the array into two.
	//Check if the item we are looking for is less than equal to or greater than the mid-point
	//If it is less than the mid-point, then we discard the greater than the mid-point portion
	//and focus on the less than point
	//We keep doing this unless we find the number
	//There are two approaches for this
	//1. Recursion
	//2. Iterative.
	std::mt19937 rng; //Random Number Generator
	rng.seed(time(NULL) );

	std::uniform_int_distribution<int> oDistN(1, nCount);
	int nNumber = 0;
	std::cout << "Unsorted Numbers: ";
	for (int i = 0; i < nCount; ++i) {
		nNumber = oDistN(rng);
		std::cout << nNumber;
		if (i < nCount)
			std::cout << " ";
		vecNumbers[i] = nNumber;
	}

	std::cout << "\n";

	std::sort(vecNumbers.begin(), vecNumbers.end());
	std::cout << "Sorted List: ";
	for (int i = 0; i < nCount; ++i) {
		std::cout << vecNumbers[i];
		if (i < nCount)
			std::cout << " ";
	}
	std::cout << "\n";

	int nNumberToSearch = oDistN(rng);
	std::cout << "Number to Search: " << nNumberToSearch << "\n";

	int nIndex = BinarySearch(vecNumbers, nNumberToSearch);
	nIndex == -1 ? std::cout << "Did not find via Recursive" << nNumberToSearch << " in the list" : std::cout << "Found " << nNumberToSearch << " at index " << nIndex << " (0 based)\n";

	nIndex = BinarySearch(vecNumbers, nNumberToSearch, false);
	nIndex == -1 ? std::cout << "Did not find via iterative" << nNumberToSearch << " in the list" : std::cout << "Found " << nNumberToSearch << " at index " << nIndex << " (0 based)\n";

	return 0;
}