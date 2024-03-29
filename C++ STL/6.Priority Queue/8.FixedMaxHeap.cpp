#include <iostream>
#include <string>
#include <queue>
using namespace std;

class FixedMaxHeap {
	int size;
	priority_queue<int> maxHeap;
public:
	FixedMaxHeap(int size = 1) {
		this -> size = size;
	}

	void setSize(int size) {
		this -> size = size;
	}

	void insert(int value) {
		if (maxHeap.size() == size) {
			if (value > maxHeap.top()) {
				return;
			}

			maxHeap.pop();
		}

		maxHeap.push(value);
	}

	int topElement() {
		return maxHeap.top();
	}

	void removeElement() {
		maxHeap.pop();
	}

	bool isEmpty() {
		return maxHeap.empty();
	}
};

int main(int argc, char const *argv[])
{
	
	return 0;
}