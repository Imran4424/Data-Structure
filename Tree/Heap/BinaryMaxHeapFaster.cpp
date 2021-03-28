#include <iostream>
using namespace std;

class MaxHeap {
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

                int largest = currentIndex;

                if (leftChild <= heapIndex && heap[leftChild] > heap[largest]) {
                        largest = leftChild;
                }

                if (rightChild <= heapIndex && heap[rightChild] > heap[largest]) {
                        largest = rightChild;
                }

                if (largest != currentIndex) {
                        swapNode(currentIndex, largest);
                        bubbleDown(largest);
                }
        }

public:
        MaxHeap() { 
                topIndex = 1;
                heapIndex = 0;
        }

        MaxHeap(int heapSize) {
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

                while(currentIndex > 1 && heap[currentIndex] > heap[parent(currentIndex)]) {
                        swapNode(currentIndex, parent(currentIndex));

                        currentIndex = parent(currentIndex);
                }

        }

        int deleteMaxElement() {
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

	MaxHeap maxHeap(25);

	for (int i = 0; i < 10; i++) {
		maxHeap.insert(arr[i]);
	}

	for (int i = 0; i < 10; i++) {
		cout << maxHeap.deleteMaxElement() << " ";
	}
	cout << endl;

	return 0;
}