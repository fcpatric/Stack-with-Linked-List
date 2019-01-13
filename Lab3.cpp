/// Lab 3, Stack with Linked List
/// Programmer: Fernando Ian Patricio
/// Programmer's ID: 1428751
/// Lab3.cpp

#include <iostream>
using namespace std;

template<class DataType>
void Stack<DataType>::deepCopy(const Stack<DataType> &original)
{
	if (original.top == NULL)
		return;

	top = new Node<DataType>;
	top->next = NULL;

	Node<DataType> *originalPtr = original.top;
	Node<DataType> *copyPtr = top;

	for (; originalPtr != NULL; originalPtr = originalPtr->next, copyPtr = copyPtr->next)
	{
		copyPtr->info = originalPtr->info;

		if (originalPtr->next != NULL)
			copyPtr->next = new Node<DataType>;

		else
			copyPtr->next = NULL;
	}
}

// Default constructor
template<class DataType>
Stack<DataType>::Stack()
{
	top = NULL;
}

// Copy constructor
template<class DataType>
Stack<DataType>::Stack(const Stack<DataType> &original)
{
	deepCopy(original);
}

// places an element onto the top of the stack
template<class DataType>
void Stack<DataType>::push(const DataType elementToBePush)
{
	Node<DataType> *newNode = new Node<DataType>; // create a node
	newNode->info = elementToBePush; // store elementToPush to this node
	newNode->next = top; // make this node point to address that the top is pointing

	top = newNode; // make top point to new node
}

// removes an element from the top of the stack and returns it in poppedElement
// returns false if called on an empty stack; otherwise, returns true
template<class DataType>
bool Stack<DataType>::pop(DataType &poppedElement)
{
	if (top == NULL)
		return false;

	poppedElement = top->info;

	Node<DataType> *temp = new Node<DataType>;
	temp = top;
	top = top->next;
	delete temp;

	return true;
}

// returns the element at the top of the stack in topElement without removing it
// returns false if called on an empty stack; otherwise, returns true
template<class DataType>
bool Stack<DataType>::peek(DataType &topElement)
{
	if (top == NULL)
		return false;

	topElement = top->info;

	return true;
}

// Overloaded opeartor= to assign a stack
template<class DataType>
Stack<DataType>& Stack<DataType>::operator=(const Stack<DataType> &original)
{
	if (this == &original)
		return *this;

	makeEmpty();
	deepCopy(original);
	return *this;
}

// returns true if the stack is empty; otherwise, returns false
template<class DataType>
bool Stack<DataType>::isEmpty() const
{
	return top == NULL;
}

// Function to make stack empty
template<class DataType>
void Stack<DataType>::makeEmpty()
{
	DataType temp;
	while (top != NULL)
		pop(temp);
}

// Destructor
template<class DataType>
Stack<DataType>::~Stack()
{
	makeEmpty();
}

// Overloaded stream insertion to output a stack
template <class DataType>
ostream& operator<<(ostream &out, const Stack<DataType> &stack)
{
	if (stack.top == NULL)
		out << "Empty\nTop->NULL";

	else
		out << "Top->";

	for (Node<DataType> *tempPtr = stack.top; tempPtr != NULL; tempPtr = tempPtr->next)
	{
		out << tempPtr->info << "->";

		if (tempPtr->next == NULL)
			out << "NULL";
	}

	out << "\n";

	return out;
}
