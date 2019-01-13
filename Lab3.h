/// Lab 3, Stack with Linked List
/// Programmer: Fernando Ian Patricio
/// Programmer's ID: 1428751
/// Lab3.h

#ifndef LAB3_H
#define LAB3_H

#include<iostream>
using std::ostream;

template<class DataType>
struct Node
{
	DataType info;
	Node<DataType> *next;
};

template <class DataType>
class Stack
{
	private:
		Node<DataType> *top;

	public:
		void deepCopy(const Stack<DataType>&);
		Stack();
		Stack(const Stack<DataType>&);
		void push(const DataType);
		bool pop(DataType&);
		bool peek(DataType&);
		Stack<DataType>& operator=(const Stack<DataType>&);
		bool isEmpty() const;
		void makeEmpty();
		~Stack();

	template <class DataType>
	friend ostream& operator<<(ostream&, const Stack<DataType>&);
};

#include "Lab3.cpp"

#endif //LAB3_H

