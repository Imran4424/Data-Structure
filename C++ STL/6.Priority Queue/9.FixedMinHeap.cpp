#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class FixedMinHeap {
	int size;
	priority_queue<int, vector<int>, greater<int> > minHeap;
public:
	FixedMinHeap(int size = 1) {
		this -> size = size;
	}

	void setSize(int size) {
		this -> size = size;
	}

	void insert(int value) {
		if (minHeap.size() == size) {
			if (value < minHeap.top()) {
				return;
			}

			minHeap.pop();
		}

		minHeap.push(value);
	}

	int topElement() {
		return minHeap.top();
	}

	void removeElement() {
		minHeap.pop();
	}

	bool isEmpty() {
		return minHeap.empty();
	}
};

int main(int argc, char const *argv[])
{
	
	return 0;
}