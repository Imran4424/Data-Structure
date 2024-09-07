/*
	1.Create a Linked List and Display it:
	Write a program to create a singly linked list and traverse and display 
	elements of the list.
*/

#include <iostream>
using namespace std;


/*
	Singly linked list have two parts

	1. Data(Value)
	2. Address - Address of next node 
*/
struct Node
{
	int data;
	// since, this pointer will hold the next Node's address
	// so, we need to declare Node type pointer to hold next Node's address
	
	// it's like, when we are trying to store int type variable's address 
	// that time we declare a int type pointer variable

	// similarly, here we need to hold Node type variable's address
	// that's why we are declaring Node type pointer variable
	Node* next;
};

// global head
// variable named head's scope is global
// it will alive in entire code from this line
Node* head;

void insertAtEnd(int value) {
	// first create the node
	
}

int main(int argc, char const *argv[])
{
	head = NULL;

	// this num variable's scope is the main function
	// after main function is finished variable will be deleted or dead
	int num;
	cout << "How many nodes you want to insert in the linked list: ";
	cin >> num;
	
	for (int i = 0; i < num; ++i) {
		// value's scope is inside this for loop
		// after loop is finished variable will be deleted or dead
		int value;
		cin >> value;

		insertAtEnd(value);
	}
	
	return 0;
}