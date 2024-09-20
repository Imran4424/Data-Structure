/*
	5. Check if Empty:
	Write a program to check if the queue is empty using an array.
*/

#include <iostream>
using namespace std;

const int SIZE = 5005;

// global array for queue
int queue[SIZE];

// global variable for front and rear index
int front = 0;
int rear = 0;

bool isEmpty() {
	return front == rear ? true : false;
}

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
	if (isEmpty()) {
		cout << "Error!!! Queue is empty" << endl;
		return;
	}

	front++;
}

// front
// will display the front of the queue
int frontOperation() {
	if (isEmpty()) {
		cout << "Error!!! Queue is empty" << endl;
		return -404;
	}

	return queue[front];
}

// rear
// will display the back of the queue
int rearOperation() {
	if (isEmpty()) {
		cout << "Error!!! Queue is empty" << endl;
		return -404;
	}

	return queue[rear - 1];
}

int main(int argc, char const *argv[])
{
	int num;
	cout << "How many nodes you want to push in the queue: ";
	cin >> num;

	if (isEmpty()) {
		cout << "Queue is empty" << endl;
	}

	for(int i = 0; i < num; ++i) {
		// value's scope is inside this for loop
		// after loop is finished variable will be deleted or dead
		int value;
		cin >> value;

		push(value);
		cout << "Front value is: " << frontOperation() << endl;
		cout << "Rear value is: " << rearOperation() << endl;
	}

	pop();
	cout << "Front value is: " << frontOperation() << endl;
	cout << "Rear value is: " << rearOperation() << endl;

	if (isEmpty()) {
		cout << "Queue is empty" << endl;
	}

	return 0;
}