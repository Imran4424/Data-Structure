#include <iostream>
#include <vector>
#include <queue>
using namespace ::std;

typedef pair<int, int> position;
typedef pair<int, position> valuePosition;

struct Compare
{
	bool operator()(valuePosition& x, valuePosition& y) {
		if (x.first < y.first) {
			return false;
		}
		else if (x.first == y.first) {
			if (x.second.first > y.second.first) {
				return false;
			}
			else if (x.second.first == y.second.first) {
				if (x.second.second > y.second.second) {
					return false;
				}
			}
		}

		return true;
	}
};

class FixMinHeap {
	priority_queue<valuePosition, vector<valuePosition>, Compare > minHeap;
	int size;
public:
	FixMinHeap(int size = 1) {
		this->size = size;
	}

	void insert(int val, position p) {
		if (size == minHeap.size()) {
			if (val < minHeap.top().first) {
				return;
			}

			if (val == minHeap.top().first) {
				if (p.first > minHeap.top().second.first) {
					return;
				}

				if (p.first == minHeap.top().second.first && p.second > minHeap.top().second.second) {
					return;
				}
			}

			minHeap.pop();
		}

		minHeap.push({ val, p });
	}

	void pop() {
		minHeap.pop();
	}

	int topVal() {
		return minHeap.top().first;
	}

	position topPosition() {
		return minHeap.top().second;
	}

	bool isEmpty() {
		return minHeap.empty();
	}
};

int main(int argc, char const *argv[])
{
	FixMinHeap myHeap(5);

	myHeap.insert(7, { 2, 3});
	myHeap.insert(7, { 4, 3});
	myHeap.insert(9, { 5, 5});
	myHeap.insert(9, { 5, 7});
	myHeap.insert(12, { 3, 3});
	myHeap.insert(15, { 7, 3});

	int value[5];
	// this is a pair array
	position point[5];
	// backward for top 5 from minHeap
	int index = 4;

	while(!myHeap.isEmpty()) {
		value[index] = myHeap.topVal();
		point[index] = myHeap.topPosition();
		myHeap.pop();
		index--;
	}

	for (int i = 0; i < 5; i++) {
		cout << "value - " << value[i]; 
		cout << ", for positions x - " << point[i].first << ", y - " << point[i].second << endl;
	}

	return 0;
}