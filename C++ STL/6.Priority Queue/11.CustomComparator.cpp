#include <iostream>
#include <queue>
#include <vector>
using namespace ::std;

struct Compare
{
	bool operator()(int &x, int &y) {
		// greater than sign between first and second parameter
		// when it's minHeap
		return x > y;
	}
};

void display(priority_queue<int, vector<int>, Compare > minHeap) {
	cout << "Min Heap Size - " << minHeap.size() << endl; 

	while(!minHeap.empty()) {
		cout << minHeap.top() << " ";
		minHeap.pop();
	}

	cout << endl;
}

int main(int argc, char const *argv[])
{
	priority_queue<int, vector<int>, Compare > minHeap;

	minHeap.push(12);
	minHeap.push(21);
	minHeap.push(55);
	minHeap.push(13);
	minHeap.push(75);
	minHeap.push(17);
	minHeap.push(7);

	display(minHeap);
	
	return 0;
}