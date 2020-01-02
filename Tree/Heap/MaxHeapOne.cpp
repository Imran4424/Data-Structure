// MAX HEAP

/*
        this is 1 index based heap

        if parent node is x then,
        left Child = 2x
        right Child = 2x + 1


        if current node is x then,
        parent node = x / 2
*/

#include <iostream>
#include <stdio.h>
using namespace std;

const int heapSize = 10000;
const int topIndex = 1;

int heap[heapSize + 1];
int heapIndex;

void SwapNode(int source, int destination)
{
	int storeValue = heap[source];

	heap[source] = heap[destination];
	heap[destination] = storeValue;
}


void BubbleUp(int currentIndex)
{
	int parentIndex = currentIndex / 2;

	if (parentIndex < 1)
	{
		return;
	}

	if (heap[currentIndex] > heap[parentIndex])
	{

		SwapNode(currentIndex, parentIndex);

		BubbleUp(parentIndex);
	}
}

void BubbleDown(int currentIndex)
{


	int leftChild = currentIndex * 2;
	int rightChild = currentIndex * 2 + 1;


	if (leftChild > heapIndex)
	{
		return;
	}

	if (rightChild > heapIndex && leftChild <= heapIndex)
	{
		if (heap[currentIndex] < heap[leftChild])
		{
			SwapNode(currentIndex, leftChild);
		}

		return;
	}

	if (heap[leftChild] > heap[currentIndex])
	{
		SwapNode(currentIndex, leftChild);

		BubbleDown(leftChild);
	}

	if(heap[rightChild] > heap[currentIndex])
	{

		SwapNode(currentIndex, rightChild);

		BubbleDown(rightChild);
	}
}

void Insert(int data)
{
	if (heapIndex >= heapSize)
	{
		return;
	}

    heapIndex++;
	heap[heapIndex] = data;

	BubbleUp(heapIndex);
}

int DeleteMaxElement()
{
	SwapNode(topIndex, heapIndex);
	heapIndex--;

	BubbleDown(topIndex);

	return heap[heapIndex + 1];
}

void DisplayHeap()
{
        for (int i = topIndex; i <= heapIndex; i++)
        {
                cout << heap[i] << " ";
        }

        cout << endl;
}

int main()
{
	heapIndex = 0;

        cout << "how many elements you want to insert in the heap?" << endl;
        int elementSize;
        cin >> elementSize;

        for (int i = 0; i < elementSize; i++)
        {
                int input;
                cin >> input;

                Insert(input);
        }

        DisplayHeap();

        for (int i = 0; i < elementSize; i++)
        {
                cout << DeleteMaxElement() << endl;
        }

	return 0;
}

/*
        equation for 0 index based heap

        if parent node is x then,
        left Child = 2x + 1
        right Child = 2x + 2


        if current node is x then,
        parent node = (x - 1) / 2
*/

