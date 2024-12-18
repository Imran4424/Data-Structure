/*
	1. Basic Max-Heap Creation:
	Write a program to create a max-heap from the following 
	values: 10, 20, 30, 40, 50, 60, 70. Display the structure of the heap.
*/

/*
        this is 0 index based heap

        if parent node is x then,
        left Child = 2x + 1
        right Child = 2x + 2


        if current node is x then,
        parent node = (x - 1) / 2
*/

/*
        this is 1 index based heap

        if parent node is x then,
        left Child = 2x
        right Child = 2x + 1


        if current node is x then,
        parent node = x / 2
*/

/*
	In this code we gonna use 1 index based heap
*/

#include <iostream>
using namespace std;

const int heapSize = 18018;
// topIndex is 1 because, this is 1 index based heap
const int topIndex = 1;

// this is our heap tree array
int heap[heapSize + 1];

// main insertion and deletion index of heap
// it also denotes the current element size of heap
int heapIndex;

void swapNode(int source, int destination) {
	int storeValue = heap[source];
	heap[source] = heap[destination];
	heap[destination] = storeValue;
}

void bubbleDown(int parentIndex) {
	// checking if this is outside of the tree or not
	if (parentIndex > heapIndex) {
		return;
	}

	int leftChildIndex = parentIndex * 2;
	int rightChildIndex = parentIndex * 2 + 1;

	// checking if this is outside of the tree or not
	if (leftChildIndex > heapIndex) {
		return;
	}

	if (heap[parentIndex] < heap[leftChildIndex]) {
		swapNode(parentIndex, leftChildIndex);

		bubbleDown(leftChildIndex);
	}

	// checking if this is outside of the tree or not
	if (rightChildIndex > heapIndex) {
		return;
	}

	if (heap[parentIndex] < heap[rightChildIndex]) {
		swapNode(parentIndex, rightChildIndex);

		bubbleDown(rightChildIndex);
	}
}

void displayHeap() {
	cout << "current heap elements" << endl;

	// since this is 1 index heap
	for (int i = 1; i <= heapIndex; ++i) {
		cout << heap[i] << " ";
	}

	cout << endl << endl;
}

int main(int argc, char const *argv[])
{
	// heapIndex 0 indicates current heap is empty
	heapIndex = 0;

	cout << "how many elements you want to insert in the heap?" << endl;

	int elementSize;
        cin >> elementSize;

        for (int i = 0; i < elementSize; ++i) {
        	int input;
                cin >> input;

                heap[++heapIndex] = input;
        }

        for (int i = 1; i * i <= elementSize; ++i) {
        	bubbleDown(topIndex);
        }

        displayHeap();
	
	return 0;
}