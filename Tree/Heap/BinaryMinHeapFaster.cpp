#include <iostream>
using namespace std;

class MinHeap {
        int topIndex;
        int heapIndex;
        int heapSize;
        int *heap;

        void swapNode(int source, int destination) {
                int temp = heap[source];
                heap[source] = heap[destination];
                heap[destination] = temp;
        }

        int parent(int currentIndex) {
                return currentIndex / 2;
        }

        void bubbleDown(int currentIndex) {
                if (currentIndex > heapIndex) {
                        return;
                }

                int leftChild = currentIndex * 2;
                int rightChild = currentIndex * 2 + 1;

                int smallest = currentIndex;

                if (leftChild <= heapIndex && heap[leftChild] < heap[smallest]) {
                        smallest = leftChild;
                }

                if (rightChild <= heapIndex && heap[rightChild] < heap[smallest]) {
                        smallest = rightChild;
                }

                if (smallest != currentIndex) {
                        swapNode(currentIndex, smallest);
                        bubbleDown(smallest);
                }
        }

public:
        MinHeap() { 
        	topIndex = 1;
        	heapIndex = 0;
        }

        MinHeap(int heapSize) {
        	topIndex = 1;
        	heapIndex = 0;
                this -> heapSize = heapSize;
                heap = new int[heapSize + 1];
        }

        void insert(int data) {
                if (heapIndex >= heapSize) {
                        return;
                }

                heap[++heapIndex] = data;
                
                // Fix the min heap property if it is violated
                int currentIndex = heapIndex;

                while(currentIndex > 1 && heap[currentIndex] < heap[parent(currentIndex)]) {
                        swapNode(currentIndex, parent(currentIndex));

                        currentIndex = parent(currentIndex);
                }

        }

        int deleteMinElement() {
                if (heapIndex < topIndex) {
                        return 0;
                }

                swapNode(topIndex, heapIndex);
                heapIndex--;
                bubbleDown(topIndex);

                return heap[heapIndex + 1];
        }

        int top() {
                return heap[topIndex];
        }

        int size() {
                return heapIndex;
        }
};

int main(int argc, char const *argv[])
{
	int arr[10] = {18, 12, 22, 12, 11, 21, 23, 58, 66, 77};

	MinHeap minHeap(25);

	for (int i = 0; i < 10; i++) {
		minHeap.insert(arr[i]);
	}

	for (int i = 0; i < 10; i++) {
		cout << minHeap.deleteMinElement() << " ";
	}
	cout << endl;

	return 0;
}