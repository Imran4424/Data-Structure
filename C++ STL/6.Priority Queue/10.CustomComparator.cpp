#include <iostream>
#include <queue>
#include <vector>
using namespace ::std;

struct Compare
{
	bool operator()(int &x, int &y) {
		// less than sign between first and second parameter
		// when it's maxHeap
		return x < y;
	}
};

void display(priority_queue<int, vector<int>, Compare > maxHeap) {
	cout << "Max Heap Size - " << maxHeap.size() << endl; 

	while(!maxHeap.empty()) {
		cout << maxHeap.top() << " ";
		maxHeap.pop();
	}

	cout << endl;
}

int main(int argc, char const *argv[])
{
	priority_queue<int, vector<int>, Compare > maxHeap;

	maxHeap.push(12);
	maxHeap.push(21);
	maxHeap.push(55);
	maxHeap.push(13);
	maxHeap.push(75);
	maxHeap.push(17);
	maxHeap.push(7);

	display(maxHeap);
	
	return 0;
}