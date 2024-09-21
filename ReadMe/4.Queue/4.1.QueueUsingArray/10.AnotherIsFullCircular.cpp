/*
	8.Is Full logic in circular queue:
	Write a program to implement is full logic in a circular queue using an array.
*/

#include <iostream>
using namespace std;

// in circular queue
// we need to big size array
// also need to be efficient
const int SIZE = 33033;

struct Queue
{
	// global array for queue
	int queue[SIZE];

	// global variable for front and rear index
	int front = 0;
	int rear = 0;

	// these are for checking if queue is empty or not
	// count is for tracking the queue element count
	int count = 0;

	bool isEmpty() {
		return count == 0 ? true : false;
	}

	// this one also works
	// bool isFull() {
	// 	if (count == SIZE && rear % SIZE == front) {
	// 		return true;
	// 	}

	// 	return false;
	// }

	// but this one liner is much easier
	bool isFull() {
		return count == SIZE ? true : false;
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
		rear++;

		// incrementing the count
		count++;

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

		// order is important
		if (SIZE == front) {
			// resetting the front
			front = 0;
		}

		// decrementing the count
		count--;
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
};


int main(int argc, char const *argv[])
{
	Queue pritha;

	int num;
	cout << "How many nodes you want to push in the queue: ";
	cin >> num;

	if (pritha.isEmpty()) {
		cout << "Queue is empty" << endl;
	}

	for(int i = 0; i < num; ++i) {
		// value's scope is inside this for loop
		// after loop is finished variable will be deleted or dead
		int value;
		cin >> value;

		pritha.push(value);
		cout << "Front value is: " << pritha.frontOperation() << endl;
		cout << "Rear value is: " << pritha.rearOperation() << endl;
		cout << endl;
	}

	for (int i = 0; i < SIZE; ++i) {
		pritha.pop();

		cout << "Front value is: " << pritha.frontOperation() << endl;
		cout << "Rear value is: " << pritha.rearOperation() << endl;
		cout << endl;
	}

	pritha.pop();
	
	cout << "Pushing 101" << endl;
	pritha.push(101);
	cout << "Front value is: " << pritha.frontOperation() << endl;
	cout << "Rear value is: " << pritha.rearOperation() << endl;
	cout << endl;

	if (pritha.isEmpty()) {
		cout << "Queue is empty" << endl;
	}

	return 0;
}