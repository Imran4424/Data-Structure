/*
	Stack implementation with Structure way
*/

#include <iostream>
using namespace std;

struct Stack
{
	struct Node
	{
		int data;
		Node* next;

		Node() { }

		Node(int data) {
			this -> data = data;
			next = NULL;
		}
	};

	Node* head;

	Stack() {
		head = NULL;
	}

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
	// pop operation is nothing but delete at End
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

		// first we need to find the pointer of last node
		// pointer of last node is residing inside last node's previous node
		// so for deleting from end, first we need to find last node's previous node

		// find last node's previous node

		// helper pointer to traverse
		Node* travel = head;

		// travel -> next -> next will be NULL
		// when we are in node's previous node
		while(NULL != travel -> next -> next) {
			// this statment will change the pointer's pointing to the next node
			travel = travel -> next;
		}

		// now we found the last node's previous node
		// delete the last node
		travel -> next = NULL;
	}

	// peek operation
	// peek operations is also called top
	int top() {
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

	// to check if stack is empty or not
	bool isEmpty() {
		return head == NULL ? true : false;
	}
};

int main(int argc, char const *argv[])
{
	Stack prithaStack;

	int num;
	cout << "How many nodes you want to push in the stack: ";
	cin >> num;

	if (prithaStack.isEmpty()) {
		cout << "Stack is empty" << endl;
	}

	for(int i = 0; i < num; ++i) {
		// value's scope is inside this for loop
		// after loop is finished variable will be deleted or dead
		int value;
		cin >> value;

		prithaStack.push(value);
		cout << "top value is: " << prithaStack.top() << endl << endl;
	}

	prithaStack.pop();
	cout << "after pop once" << endl;
	cout << "top value is: " << prithaStack.top() << endl;

	if (prithaStack.isEmpty()) {
		cout << "Stack is empty" << endl;
	}

	return 0;
}