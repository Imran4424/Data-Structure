/*
	5.Check if Full:
	Write a program to check if the stack is full using an array.
*/

#include <iostream>
using namespace std;

const int SIZE = 5005;

// global array for stack
int stack[SIZE];

// initially top index is -1
// -1 denotes stack is empty
int topIndex = -1;

bool isEmpty() {
	return topIndex < 0 ? true : false;
}

bool isFull() {
	return topIndex + 1 == SIZE ? true : false;
}

// push for stack in array
void push(int value) {
	if (isFull()) {
		cout << "Error!!! Stack is full" << endl;
		return;
	}

	stack[++topIndex] = value;
}

// pop for stack in array
// pop operaion in stack never returns anything
// it just deletes the top element
void pop() {
	if (isEmpty()) {
		cout << "Error! There is no node in stack" << endl;
		return;
	}

	topIndex--;
}

// it will return the top element
int top() {
	return stack[topIndex];
}

int main(int argc, char const *argv[])
{
	int num;
	cout << "How many nodes you want to push in the stack: ";
	cin >> num;

	if (isEmpty()) {
		cout << "Stack is empty" << endl;
	}

	for(int i = 0; i < num; ++i) {
		// value's scope is inside this for loop
		// after loop is finished variable will be deleted or dead
		int value;
		cin >> value;

		push(value);
		cout << "top value is: " << top() << endl;
	}

	pop();

	cout << "top value is: " << top() << endl;

	if (isEmpty()) {
		cout << "Stack is empty" << endl;
	}
	
	return 0;
}