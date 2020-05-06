#pragma once

#include "Node.hpp"

template <typename T1> class List {
	public:
					List() : m_pHead(nullptr) {};
					List(const List<T>& oList);
		List<T>&	operator = (const List<T>& oList);
		virtual		~List();

		Node<T>*	GetHead() const			{ return m_pHead; };
		void		SetHead(Node<T>* pNode)	{ m_pHead = pNode; };
		bool		IsEmpty() const			{ return nullptr == GetHead(); };
		size_t		GetSize() const;

		Node<T>*	Insert(const T& oData);


		//insertion and extraction operator
		//insertion operator for inserting new nodes
		//extraction operator for printing the contents of the node on the 
		//console
		template <typename T1>
		friend std::ostream& operator<<(std::ostream& out,
										const List<T>* pList);

		template <typename T1>
		friend std::ostream& operator<<(std::ostream& out,
										const List<T>& oList);

		template <typename T1>
		friend List<T1>&	operator>>(const T1& oData, List<T1>& oList);

		template <typename T1>
		friend List<T1>&	operator>>(const T1& oData, List<T1>* pList);
	protected:
		Node<T>* m_pHead = nullptr;
};

template <typename T1>
List<T1>& operator >> (const T1& oData, List<T1>& oList) {
	//insert at head of the list
	oList.SetHead() = new Node<T1>(oData, oList.GetHead());
	return oList;
}

template <typename T1>
List<T1>& operator >> (const T1& oData, List<T1>* pList) {
	return operator >> (oData, *pList);
}

template <typename T1>
std::ostream& operator << (std::ostream& out, const List<T1>* pList) {
	return operator << (out, *pList);
}

//this prints the element of the list
template <typename T1>
std::ostream& operator << (std::ostream& out, const List<T1>& oList) {
	Node<T1> *pNode = oList.GetHead();
	
	while (pNode) {
		out << pNode;
		pNode = pNode->GetNext();
	}

	return out;
}

template <typename T1>
List<T1>& operator >> (const T1& oData, List<T1>* pList) {
	return operator >> (oData, *pList);
}

template <typename T>
Node<T>* List<T>::Insert(const T& oData);
	oData >> this;
	return GetHead();
}

template <typename T>
size_t List<T>::GetSize() const {
	Node<T>*	pNode = GetHead();
	size_t		nSize = 0;
	while (pNode) {
		++nSize;
		pNode = pNode->GetNext();
	}

	return nSize;
}
