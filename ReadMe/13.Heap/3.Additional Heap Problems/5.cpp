/*
	5. Implement Heapsort for Descending Order using a Max-Heap:
	Write a program to implement the heapsort algorithm to sort an array in descending order 
	using a max-heap. Use the array [10, 20, 30, 40, 50, 60, 70] and sort it in descending 
	order using the heapsort algorithm.
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

void bubbleUp(int currentIndex) {
	int parentIndex = currentIndex / 2;

	// checking if this is outside of the tree or not
	if (parentIndex < topIndex) {
		return;
	}

	if (heap[parentIndex] < heap[currentIndex]) {
		swapNode(parentIndex, currentIndex);

		bubbleUp(parentIndex);
	}
}

void bubbleDown(int parentIndex) {
	// checking if this is outside of the tree or not
	if (parentIndex > heapIndex) {
		return;
	}

	int leftChildIndex = parentIndex * 2;
	int rightChildIndex = parentIndex * 2 + 1;

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

void insert(int data) {
	if (heapIndex >= heapSize) {
		cout << "Error!!! heap is full" << endl;
		return;
	}

	heapIndex++;
	heap[heapIndex] = data;

	// heap[++heapIndex] = data;

	bubbleUp(heapIndex);
}

int deleteMaxElement() {
	swapNode(topIndex, heapIndex);
	heapIndex--;

	bubbleDown(topIndex);

	return heap[heapIndex + 1];
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

                insert(input);
        }

        // decending heapsort
        int arr[elementSize];

        for (int i = 0; i < elementSize; ++i) {
        	arr[i] = deleteMaxElement();
        }

        cout << "sorted array: ";

        for (int i = 0; i < elementSize; ++i) {
        	cout << arr[i] << " ";
        }

        cout << endl;
        
	return 0;
}

/*
	main array
	4 3 7 1 5

	FIRST RECURSION CALL
	4 3 7 1

	4 3 7 -> 3 4 7
	3 4 7 1

	4 7 1 -> NO SWAP

	3 4 7 -> No swap

	3 4 7 1

	main array
	3 4 7 1 5

	SECOND RECURSION CALL

	4 7 1 5

	4 7 1
	7 1 5 -> 1 7 5
	4 1 7 -> 1 4 7

	1 4 7 5
	
	main array
	3 1 4 7 5
	
	THIRD RECURSION CALL

	3 1 4 7

	3 1 4 -> 1 3 4
	1 3 4 7

	3 4 7
	
	1 3 4

	main array
	1 3 4 7 5
*/