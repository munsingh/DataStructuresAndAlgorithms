#include <iostream>
#include <vector>

using std::vector;

class Item {
	public:
		Item(double dValue, int nWeight)
			: m_dValue(dValue), m_nWeight(nWeight) {
			m_dValuePerUnit = m_nWeight > 0 ? m_dValue / m_nWeight : 0;
		};
		~Item() {};

		double	GetPerUnitValue() const {
			return m_dValuePerUnit;
		};

		double GetValue() const { return m_dValue; };
		void SetValue(const double dValue) { m_dValue = dValue; };

		int GetWeight() const { return m_nWeight; };
		void SetWeight(const int nWeight) { m_nWeight = nWeight; };

		//overloaded greater than, less than operator
		friend bool operator == (const Item& oItem1, const Item& oItem2) {
			return oItem1.GetPerUnitValue() == oItem2.GetPerUnitValue();
		};

		friend bool operator != (const Item& oItem1, const Item& oItem2) {
			return oItem1.GetPerUnitValue() != oItem2.GetPerUnitValue();
		};

		friend bool operator > (const Item& oItem1, const Item& oItem2) {
			return oItem1.GetPerUnitValue() > oItem2.GetPerUnitValue();
		};

		friend bool operator < (const Item& oItem1, const Item& oItem2) {
			return oItem1.GetPerUnitValue() < oItem2.GetPerUnitValue();
		};

		friend bool operator >= (const Item& oItem1, const Item& oItem2) {
			return oItem1.GetPerUnitValue() >= oItem2.GetPerUnitValue();
		};

		friend bool operator <= (const Item& oItem1, const Item& oItem2) {
			return oItem1.GetPerUnitValue() <= oItem2.GetPerUnitValue();
		};
	private:
		Item();
		double	m_dValue = 0.0;
		int		m_nWeight = 0;
		double  m_dValuePerUnit = 0.0;
};

template <class T> class Node {
	public:
						Node(const T& oData, Node<T>* pNext = nullptr) : m_oData(oData), m_pNext(pNext) {};
						Node(const Node<T>& oNode) : Node(oNode.GetData(), oNode.GetNext()) {};
						Node(const Node<T>* pNode) : Node(*pNode) {};
		virtual			~Node() { SetNext(); };
		Node<T>&		operator=(const Node<T>& oNode) {
			if (this != &oNode) {
				this->SetData(oNode.GetData());
				this->SetNext(oNode.GetNext());
			}

			return *this;
		};

		T&				GetData() { return m_oData; };
		const T&		GetData() const { return m_oData; };
		Node<T>*		GetNext()  { return m_pNext; };
		const Node<T>*	GetNext() const { return m_pNext; };

		void			SetData(const T& oData) { m_oData = oData; };
		void			SetNext(Node<T>* pNext = nullptr)  { m_pNext = pNext; };

		friend std::ostream& operator << (std::ostream& out, const Node<T>* pNode) {
			out << pNode->GetData();
			return out;
		};
	private:
		T			m_oData;
		Node<T>*	m_pNext = nullptr;
};

template <class T> class List {
	public:
						List(bool bSorted = false, bool bAscending = false)
							: m_pHead(nullptr), m_bSorted(bSorted), m_bAscending(bAscending) {};
						List(const List& oList);
				virtual ~List() { ClearList(); };

				Node<T>*		Add(const T& oData);
				Node<T>*		SetHead(Node<T>* pNode) { m_pHead = pNode; return GetHead(); };
				const Node<T>*	GetHead() const { return m_pHead; };
				Node<T>*		GetHead() { return m_pHead; };
				Node<T>*		DeleteHead();

				virtual bool	Compare(const T& oData1, const T& oData2);

		void	ClearList();
	private:
		Node<T>* m_pHead = nullptr;
		bool	 m_bSorted = true;
		bool	 m_bAscending = false;
};

template <class T> Node<T>* List<T>::DeleteHead() {
	Node<T>* pCurrentHead = GetHead();
	SetHead(pCurrentHead->GetNext());
	delete pCurrentHead;
	pCurrentHead = nullptr;
	return GetHead();
}

template <class T> bool List<T>::Compare(const T& oData1, const T& oData2) {
	//return true if oData1 is equal to or greater than oData2
	return m_bAscending ? oData1 < oData2 : oData1 > oData2;
}

template <class T> Node<T>*	List<T>::Add(const T& oData) {
	Node<T>* pNewNode = new Node<T>(oData);

	if (m_bSorted) {
		//Add Node in sorted order
		//This will depend on the sorting order as well ascending or desending
		//If ascending, then head should contain the smallest value node
		//otherwies the head will contain the highest value node
		Node<T>* pCurr = GetHead();
		Node<T>* pPrev = nullptr;

		if (nullptr == pCurr) {
			//empty list
			//add the new node as Head
			SetHead(pNewNode);
			return GetHead();
		}
		
		while (pCurr && this->Compare(pCurr->GetData(), oData)) {
			pPrev = pCurr;
			pCurr = pCurr->GetNext();
		}

		//The new node has to be inserted between pCurr and pNode
		if (pPrev == nullptr) {
			//head node
			pNewNode->SetNext(GetHead());
			SetHead(pNewNode);
		}
		else {
			pNewNode->SetNext(pPrev->GetNext());
			pPrev->SetNext(pNewNode);
		}

		return pNewNode;
	}
	else {
		pNewNode->SetNext(GetHead());
		SetHead(pNewNode);
		return GetHead();
	}
}

template <class T> void List<T>::ClearList() {
	//empties the list
	Node<T>* pNode = nullptr;

	while( nullptr != (pNode = GetHead())) {
		SetHead(GetHead()->GetNext());
		delete pNode;
	}
}

double get_optimal_value(int nCapacity, List<Item>& oList) {
	double dValue = 0.0;

	// start with the capacity and iterate the list, the biggest item in the list is the first entry
	//Take all of it if you can otherwise take only how much you can to fill the knapsack.
	// Check if that item is less than the capacity, if it is subtract the weight from the capacity
	// and add the value of the item added.
	Node<Item>* pHead = oList.GetHead();
	int nWeight = 0;
	while (nCapacity != 0 && nullptr != pHead) {
		nWeight = pHead->GetData().GetWeight();
		if (nWeight <= nCapacity) {
			//take whole of it
			nCapacity -= nWeight;
			dValue += pHead->GetData().GetValue();
			//this Item is used, so remove it from the list
			pHead = oList.DeleteHead();
		}
		else {
			//take what you can
			//So if capacity is for example 12 and the weight of item is 20 
			//then take the capacity equivalent of weight
			//in this case Value = Weight taken * PerUnitValue
			//Update the item with reamaning weight and value
			
			dValue += nCapacity * pHead->GetData().GetPerUnitValue();
			
			pHead->GetData().SetWeight(nWeight - nCapacity);
			pHead->GetData().SetValue(pHead->GetData().GetPerUnitValue() * 
									 (nWeight - nCapacity));

			nCapacity = 0;
		}
	}

	return dValue;
}

/*
  We store the items in descending order of value per unit.
  For this we are using a custom List class
 */
int main() {
	int nNumberOfItems = 0;	//Number of itms
	int nCapacity = 0;		//Capacity of the knapsack
	std::cin >> nNumberOfItems >> nCapacity;
  
	double dValue;
	int nWeight;
	List<Item> oList(true);
	std::vector<Item*> vecItems(nNumberOfItems);
	Item* pItem = nullptr;
  
	for (int i = 0; i < nNumberOfItems; i++) {
		std::cin >> dValue >> nWeight;
		pItem = new Item(dValue, nWeight);
		vecItems[i] = pItem;
		oList.Add(*pItem);
	}

	double optimal_value = get_optimal_value(nCapacity, oList);

	std::cout.precision(10);
	std::cout << optimal_value << std::endl;

	for (int i = 0; i < nNumberOfItems; i++) {
		delete vecItems[i];
	}

	return 0;
}
