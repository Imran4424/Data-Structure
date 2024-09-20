/*
	7. workaround if Full:
	Write a program to implement a workaround if the queue is full using an array.
*/

#include <iostream>
using namespace std;

const int SIZE = 7;

// global array for queue
int queue[SIZE];

// global variable for front and rear index
int front = 0;
int rear = 0;

// these are for checking if queue is empty or not
// in circular array based queue situation
// int prevFront = 0;
int prevRear = 0;

bool isEmpty() {
	if (prevRear == rear && front == rear) {
		return true;
	}

	return false;
}

bool isFull() {
	if (rear % SIZE == front) {
		return true;
	}

	return false;
}

// push for queue in array
void push(int value) {
	if (SIZE == rear) {
		if(isFull()) {
			cout << "Error!!! queue is full" << endl;
			return;
		}

		// reseting the rear
		rear = 0;
	}

	queue[rear] = value;
	prevRear = rear;
	rear++;

	// queue[rear++] = value;
}

// pop for queue in array
// pop operaion in queue never returns anything
// it just deletes the front element
void pop() {
	if (SIZE == rear) {
		if (isEmpty()) {
			cout << "Error!!! Queue is empty" << endl;
			return;
		}

		// resetting the front
		front = 0;
	}

	// prevFront = front;
	prevRear = rear;
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