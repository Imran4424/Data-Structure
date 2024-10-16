
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


int main(int argc, char const *argv[])
{
	// heapIndex 0 indicates current heap is empty
	heapIndex = 0;
	
	return 0;
}