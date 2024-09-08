/*
	3.Insert at Beginning:
	Write a program to insert a node at the beginning of a singly linked list.
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

	Node() {
		data = 0;
		next = NULL;
	}

	Node(int data) {
		this -> data = data;
		next = NULL;
	}
};

// global head
// variable named head's scope is global
// it will alive in entire code from this line
Node* head;

void insertAtEnd(int value) {
	Node *tempNode = new Node(value);
	
	if (NULL == head) {
		head = tempNode;
		return;
	}

	// helper pointer to traverse
	Node* travel = head;

	while(NULL != travel -> next) {
		// this statement will change the pointer's pointing to the next node
		// why we are doing this
		// cause we need to find the last node
		// so we gonna do this until we find the last node
		travel = travel -> next;
	}

	// adding the new node at the end of last node
	travel -> next = tempNode;
}

void insertAtBegin(int value) {
	Node *tempNode = new Node(value);

	if (NULL == head) {
		head = tempNode;
		return;
	}

	// need to add node at the begin of linked list

	// first link the whole linked list to the end of new node
	// here, head is representing the whole current linked list
	tempNode -> next = head;

	// now change the head's node pointing to the new node
	head = tempNode;
}

void display() {
	// helper pointer to traverse
	Node* travel = head;

	while(NULL != travel) {
		cout << travel -> data << " ";
		// this statment will change the pointer's pointing to the next node
		travel = travel -> next;
	}
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

		insertAtBegin(value);
	}

	// now display the linked list
	display();
	
	return 0;
}