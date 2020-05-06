#pragma once

#include <iostream>

template <typename T> class Node {
	public:
		Node(T oData, Node<T>* pNext = nullptr)
			: m_oData(oData), m_pNext(pNext) {};
		
		~Node() {
			SetNext(nullptr);
		}

		Node<T>*	GetNext() const			{ return m_pNext; };
		void		SetNext(Node<T>* pNext) { m_pNext = pNext; };

		T			GetData()				{ return m_oData; };
		void		SetData(const T& oData) { m_oData = oData; };

		//overload the insertion and extraction operators 
		//the extraction operator prints the data on the console

		//The insertion operator inserts the data into the node
		template <typename T1>
		friend std::ostream& operator << (std::ostream& out,
										  const Node<T1>* pNode);
	protected:
		T			m_oData;
		Node<T>*	m_pNext;
	private:
		//hidden copy constructor and assignment operator
		Node(const Node<T>& oNode);
		Node<T>& operator = (const Node<T>& oNode);
};

template <typename T1>
std::ostream& operator << (std::ostream& out, const Node<T1>* pNode) {
	out << pNode->GetData() << "->";
	
	if (nullptr == pNode->GetNext()) {
		out << "NULL";
	}

	return out;
}