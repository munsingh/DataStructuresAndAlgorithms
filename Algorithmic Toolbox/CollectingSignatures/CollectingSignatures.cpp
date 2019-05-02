#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

//struct Segment {
//  int start, end;
//};
//
//vector<int> optimal_points(vector<Segment> &segments) {
//  vector<int> points;
//  //write your code here
//  for (size_t i = 0; i < segments.size(); ++i) {
//    points.push_back(segments[i].start);
//    points.push_back(segments[i].end);
//  }
//  return points;
//}

class Segment {
	public:
		Segment() : m_nStart(0), m_nEnd(0) {};
		~Segment() {};

		const int	GetStartPoint() const	{ return m_nStart; };
		const int	GetEndPoint() const		{ return m_nEnd; };
		int			GetStartPoint()			{ return m_nStart; };
		int			GetEndPoint()			{ return m_nEnd; };

		//overloaded insertion operator
		friend std::istream& operator >> (std::istream& in, Segment& oSegment) {
			in >> oSegment.m_nStart;
			in >> oSegment.m_nEnd;

			return in;
		}

		//overloaded comparison operators
		friend bool operator == (const Segment& oLHS, const Segment& oRHS) {
			return oLHS.GetEndPoint() == oRHS.GetEndPoint();
		};

		friend bool operator != (const Segment& oLHS, const Segment& oRHS) {
			return oLHS.GetEndPoint() != oRHS.GetEndPoint();
		};

		friend bool operator > (const Segment& oLHS, const Segment& oRHS) {
			return oLHS.GetEndPoint() > oRHS.GetEndPoint();
		};

		friend bool operator < (const Segment& oLHS, const Segment& oRHS) {
			return oLHS.GetEndPoint() < oRHS.GetEndPoint();
		};

		friend bool operator >= (const Segment& oLHS, const Segment& oRHS) {
			return oLHS.GetEndPoint() >= oRHS.GetEndPoint();
		};

		friend bool operator <= (const Segment& oLHS, const Segment& oRHS) {
			return oLHS.GetEndPoint() <= oRHS.GetEndPoint();
		};
	private:
		int	m_nStart = 0;
		int m_nEnd = 0;
};

template <class T> class Node {
	public:
				Node(const T& oData, Node<T>* pNext = nullptr)
					:m_oData(oData), m_pNext(pNext) {};
				Node(const Node& oNode) {
					*this = oNode;
				}
				Node(const Node* pNode) :
					Node(*pNode) {};
				Node<T>& operator = (const Node& oNode) {
					if (*this != oNode) {
						this->SetData(oNode.GetData());
						this->SetNext(oNode.GetNext());
					}

					return *this;
				}
		virtual ~Node() { m_pNext = nullptr; };

		Node<T>*		GetNext()				{ return m_pNext; };
		const Node<T>*	GetNext() const			{ return m_pNext; };
		T&				GetData()				{ return m_oData; };
		const T&		GetData() const			{ return m_oData; };
		void			SetData(const T& oData) { m_oData = oData; };
		void			SetNext(Node* pNext)	{ m_pNext = pNext; };
	private:
		T				m_oData;
		Node<T>*		m_pNext = nullptr;
};

template <class T> class List {
	public:
				List(bool bSorted = true, bool bAscending = true) :
					m_pHead(nullptr), m_bSorted(bSorted), m_bAscending(bAscending) {};
		virtual ~List() { ClearList(); };
		
		virtual bool	Compare(const T& oData1, const T& oData2);
		Node<T>*		DeleteHead();
		void			ClearList();
		Node<T>*		GetHead()				{ return m_pHead; };
		const Node<T>*	GetHead() const			{ return m_pHead; };
		void			SetHead(Node<T>* pNode) { m_pHead = pNode; };
		Node<T>*		AddNode(const T& oData);
		
		friend std::istream& operator >> (std::istream& in, List<T>& oList) {
			T oData;
			in >> oData;
			oList.AddNode(oData);

			return in;
		};
	private:
		Node<T>*	m_pHead;
		bool		m_bSorted = true;
		bool		m_bAscending = true;
};

template <class T> bool List<T>::Compare(const T& oData1, const T& oData2) {
	//Comparison depends on the sort order
	//if ascending then oData1 should be less than oData2 otherwise oData1 should be greater than oData2
	return m_bAscending ? oData1 < oData2 : oData1 > oData2;
}

template <class T> Node<T>* List<T>::AddNode(const T& oData) {
	Node<T>* pNewNode = new Node<T>(oData);

	if (nullptr == GetHead()) {
		//this is the first node, hence the head
		SetHead(pNewNode);
	}
	else {
		//not the fist node
		//node needs to be added based on the sorting and the soring order
		if (m_bSorted) {
			Node<T>* pCurr = GetHead();
			Node<T>* pPrev = nullptr;

			while (pCurr && Compare(pCurr->GetData(), oData)) {
				pPrev = pCurr;
				pCurr = pCurr->GetNext();
			}

			//we need to insert between pPrev and pCurr
			if (pPrev) {
				pNewNode->SetNext(pPrev->GetNext());
				pPrev->SetNext(pNewNode);
			}
			else {
				//pPrev is nullptr, which means the list has only one node
				pNewNode->SetNext(pCurr);
				SetHead(pNewNode);
			}
		}
		else {
			//not sorted. So add as Head
			pNewNode->SetNext(GetHead());
			SetHead(pNewNode);
		}
	}

	return pNewNode;
}

template <class T> void List<T>::ClearList() {
	while (GetHead())
		DeleteHead();
}

template <class T> Node<T>*	List<T>::DeleteHead() {
	Node<T>* pCurrentHead = GetHead();
	SetHead(pCurrentHead->GetNext());
	delete pCurrentHead;
	pCurrentHead = nullptr;

	return GetHead();
}

template <class T> void GetOptimalPoints(List<T>& oList, std::vector<int>& vecPoints) {
	//take the first end-point from the first pair
	//Check if it exists between the next pair
	//If it exists move to the next pair
	//otherwise change the end-point to the next pair's end point
	//and add this end-point to the set of points
	Node<T> *pHead = oList.GetHead();
	if (nullptr == pHead)
		return;

	int nEndPoint = pHead->GetData().GetEndPoint();
	vecPoints.push_back(nEndPoint);
	Node<T>* pCurrNode = pHead->GetNext();
	while (pCurrNode) {
		if (nEndPoint >= pCurrNode->GetData().GetStartPoint() && nEndPoint <= pCurrNode->GetData().GetEndPoint()) {
			//nEndPoint is within the segment
			;
		}
		else {
			//not in the segment
			nEndPoint = pCurrNode->GetData().GetEndPoint();
			vecPoints.push_back(nEndPoint);
		}
		pCurrNode = pCurrNode->GetNext();
	}

}

int main() {
	size_t nNumberOfSegments;
	std::cin >> nNumberOfSegments;
	List< Segment > oSegments;
	
	for (size_t i = 0; i < nNumberOfSegments; ++i) {
		std::cin >> oSegments;
	}

	std::vector<int> vecPoints;
	GetOptimalPoints(oSegments, vecPoints);
	std::cout << vecPoints.size() << "\n";

	for (size_t i = 0; i < vecPoints.size(); ++i) {
		std::cout << vecPoints[i] << " ";
	}
}