/*
	4.Rear Operation(Top)
	Write a program to implement the rear operation in a queue using a linked list.
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

	Node() { }

	Node(int data) {
		this -> data = data;
		next = NULL;
	}
};

// global head
// variable named head's scope is global
// it will alive in entire code from this line
Node* head;

// push operation
// push operation is nothing but insert at End
void push(int value) {
	Node *tempNode = new Node(value);
	
	if (NULL == head) {
		head = tempNode;
		return;
	}

	// helper pointer to traverse
	Node* travel = head;

	// travel next will be NULL
	// when we are in last node
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

// pop operation
// pop operation is nothing but delete at Begin
void pop() {
	// linklist has no nodes
	if (NULL == head){
		cout << "Error! There is no node" << endl;
		return;
	}

	// linklist has only one node
	if (NULL == head -> next) {
		head = NULL;
		// cause after deleting the last node there won't be any nodes in the linked list
	}

	// linked has multiple nodes
	// delete the first node
	head = head -> next;
}

// front
// will display the front of the queue
int front() {
	// queue is empty or not
	if (NULL == head) {
		cout << "Error!!! Queue is empty" << endl;
		return -404;
	}

	return head -> data;
}

// rear
// will display the back of the queue
int rear() {
	if (NULL == head){
		cout << "Error! There is no node in stack" << endl;
		return -404;
	}


	// helper pointer to traverse
	Node* travel = head;

	// travel -> next will be NULL
	// when we are in last node
	while(NULL != travel -> next) {
		// this statement will change the pointer's pointing to the next node
		// why we are doing this
		// cause we need to find the last node
		// so we gonna do this until we find the last node
		travel = travel -> next;
	}

	// now we are at last node
	// just return the last node value
	return travel -> data;
}

int main(int argc, char const *argv[])
{
	// head = NULL;
	int num;
	cout << "How many nodes you want to push in the queue: ";
	cin >> num;

	for(int i = 0; i < num; ++i) {
		// value's scope is inside this for loop
		// after loop is finished variable will be deleted or dead
		int value;
		cin >> value;

		push(value);
		cout << "Front value is: " << front() << endl;
		cout << "Rear value is: " << rear() << endl;
	}

	pop();

	cout << "Front value is: " << front() << endl;
	cout << "Rear value is: " << rear() << endl;


	return 0;
}