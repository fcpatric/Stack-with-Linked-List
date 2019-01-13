/// Lab 3, Stack with Linked List
/// Programmer: Fernando Ian Patricio
/// Programmer's ID: 1428751
/// DriverLab3.cpp

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>

#include "Lab3.h"

int main()
{
	Stack<int> s1;
	cout << "Stack 1: " << s1 << endl;

	string checkDefaultConstructor;
	string checkIsEmpty;
	if (s1.isEmpty())
	{
		cout << "Checking isEmpty() function...\n";
		cout << "s1 is empty.\n\n";
	  checkDefaultConstructor = "default constructor is green";
	  checkIsEmpty = "isEmpty is green.";
	}
	
	cout << "Pushing 6...\n";
	s1.push(6);
	string checkPush = "push is green.";
	cout << "Stack 1: " << s1 << endl;

	int poppedElement1;
	s1.pop(poppedElement1);
	string checkPop = "pop is green;";

	cout << "Popped Element1: " << poppedElement1 << endl;
	cout << "Stack 1: " << s1 << endl;

	cout << "Pushing 7 and 99...\n";
	s1.push(7);
	s1.push(99);
	cout << "Stack 1: " << s1 << endl;

	int poppedElement2;
	s1.pop(poppedElement2);
	cout << "Popped Element2: " << poppedElement2 << endl;
	cout << "Stack 1: " << s1 << endl;

	cout << "Pushing 8, 9 and 6...\n";
	s1.push(8);
	s1.push(9);
	s1.push(6);
	cout << "Stack 1: " << s1 << endl;

	int topElement1;
	s1.peek(topElement1);
	string checkPeek = "peek is green;";
	cout << "Top Element1: " << topElement1 << endl;
	cout << "Stack 1: " << s1 << endl;

	if (!s1.isEmpty())
	{
		cout << "Checking isEmpty() function...\n";
		cout << "s1 is not empty.\n\n";
	}
	
	cout << "Before the copy, Stack 1: " << s1;
	Stack<int> s2(s1);
	string checkCopyConstructor = "copy constructor is green;";
	cout << "Copying Stack 1 to Stack 2 with Copy Constructor...\n";
	cout << "Stack 1: " << s1;
	cout << "Stack 2: " << s2 << endl;

	Stack<int> s3;
	s3.push(25);
	s3.push(35);
	s3.push(11);
	s3.push(56);
	s3.push(60);

	Stack<int> s4;
	s4 = s3;
	string checkAssignmentOperator = "operator= is green.";
	cout << "Before the assignment, Stack 3: " << s3;
	cout << "Assigning Stack 3 to Stack 4 with Operator=...\n";
	cout << "Stack 3: " << s3;
	cout << "Stack 4: " << s4 << endl;

	cout << "Emptying Stack 1 by calling the destructor...\n";
	s1.~Stack();
	string checkDestructor = "destructor is green.";
	cout << "Stack 1: " << s1 << endl;

	cout << "Emptying Stack 4 by calling makeEmpty()...\n";
	s4.makeEmpty();
	string checkMakeEmpty = "makeEmpty is green.";
	cout << "Stack 4: " << s4 << endl;

	cout << "Attempting to copy Stack 1 with Copy Constructor which is empty to Stack 5.\n";
	Stack<int> s5(s1);
	cout << "Stack 1: " << s1;
	cout << "Stack 5: " << s5 << endl;
	
	cout << "Attempting to assign Stack 4 with Operator= which is empty to Stack 6.\n";
	Stack<int> s6 = s4;
	cout << "Stack 4: " << s4;
	cout << "Stack 6: " << s6 << endl;

	cout << checkDefaultConstructor << endl;
	cout << checkIsEmpty << endl;
	cout << checkPush << endl;
	cout << checkPop << endl;
	cout << checkPeek << endl;
	cout << checkCopyConstructor << endl;
	cout << checkAssignmentOperator << endl;
	cout << checkDestructor << endl;
	cout << checkMakeEmpty << endl;

	char choice;
	cout << "\nEnter E to exit.\n";
	cout << ">";
	cin >> choice;
}
