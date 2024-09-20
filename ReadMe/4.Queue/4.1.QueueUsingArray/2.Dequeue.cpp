/*
	2. Enqueue Operation:
	Write a program to implement the dequeue operation in a queue using an array.
*/

#include <iostream>
using namespace std;

const int SIZE = 5005;

// global array for queue
int queue[SIZE];

// global variable for front and rear index
int front = 0;
int rear = 0;

// push for queue in array
void push(int value) {
	queue[rear] = value;
	rear++;

	// queue[rear++] = value;
}

// pop for queue in array
// pop operaion in queue never returns anything
// it just deletes the front element
void pop() {
	front++;
}

int main(int argc, char const *argv[])
{
	int num;
	cout << "How many nodes you want to push in the queue: ";
	cin >> num;

	for(int i = 0; i < num; ++i) {
		// value's scope is inside this for loop
		// after loop is finished variable will be deleted or dead
		int value;
		cin >> value;

		push(value);
	}

	pop();

	return 0;
}