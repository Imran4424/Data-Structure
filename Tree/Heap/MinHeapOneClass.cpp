class MinHeap {
        int topIndex = 1;
        int heapIndex = 0;
        int heapSize;
        int *heap;

        void swapNode(int source, int destination) {
                int temp = heap[source];
                heap[source] = heap[destination];
                heap[destination] = temp;
        }

        void bubbleUp(int currentIndex) {
                int parentIndex = currentIndex / 2;

                if (parentIndex < topIndex) {
                        return;
                }

                if (heap[currentIndex] < heap[parentIndex]) {
                        swapNode(currentIndex, parentIndex);
                        bubbleUp(parentIndex);
                }
        }

        void bubbleDown(int currentIndex) {
                if (currentIndex > heapIndex) {
                        return;
                }

                int leftChild = currentIndex * 2;
                int rightChild = currentIndex * 2 + 1;

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

public:
        MinHeap() { }

        MinHeap(int heapSize) {
                this -> heapSize = heapSize;
                heap = new int[heapSize + 1];
        }

        void insert(int data) {
                if (heapIndex >= heapSize) {
                        return;
                }

                heap[++heapIndex] = data;
                bubbleUp(heapIndex);
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
