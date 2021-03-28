// MIN HEAP
/*
        this is 0 index based heap

        if parent node is x then,
        left Child = 2x + 1
        right Child = 2x + 2


        if current node is x then,
        parent node = (x - 1) / 2
*/

#include <iostream>
#include <stdio.h>
using namespace std;

const int heapSize = 1000;
const int topIndex = 0;

int heap[heapSize + 1];
int heapIndex;

void initHeap()
{
	heapIndex = -1;
}

void SwapNode(int source, int destination)
{
	int storeValue = heap[source];

	heap[source] = heap[destination];
	heap[destination] = storeValue;
}

void BubbleUp(int currentIndex)
{
    if(currentIndex < 0)
    {
        return;
    }

    int parent = (currentIndex - 1) / 2;

    if(heap[parent] > heap[currentIndex])
    {
        SwapNode(currentIndex, parent);

        BubbleUp(parent);
    }
}

void Insert(int value)
{
	if(heapIndex > heapSize)
    {
        return;
    }

    heapIndex++;
    heap[heapIndex] = value;

    BubbleUp(heapIndex);
}

void BubbleDown(int currentIndex)
{
    if (currentIndex > heapIndex) {
                return;
        }

        int leftChild = currentIndex * 2 + 1;
        int rightChild = currentIndex * 2 + 2;

        if (leftChild > heapIndex) {
                return;
        }

        if (heap[currentIndex] > heap[leftChild]) {
                swapNode(currentIndex, leftChild);
                bubbleDown(leftChild);
        }

        if (rightChild > heapIndex) {
                return;
        }

        if (heap[currentIndex] > heap[rightChild]) {
                swapNode(currentIndex, rightChild);
                bubbleDown(rightChild);
        }
}

int DeleteMinElement()
{
    if(0 > heapIndex)
    {
        return -1;
    }

    SwapNode(0, heapIndex);
    heapIndex--;

    BubbleDown(topIndex);

    return heap[heapIndex + 1];
}

void DisplayHeap()
{
        while(heapIndex >= 0)
        {
            cout << DeleteMinElement() << " ";
        }

        cout << endl;
}

int main()
{
        initHeap();

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

	return 0;
}

/*
        equation for 1 index based heap

        if parent node is x then,
        left Child = 2x
        right Child = 2x + 1


        if current node is x then,
        parent node = x / 2
*/

