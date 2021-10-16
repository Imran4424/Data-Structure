#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void displayMaxHeap(priority_queue<int> maxHeap) {
	cout << "Max heap size - " << maxHeap.size() << endl; 

	while(!maxHeap.empty()) {
		cout << maxHeap.top() << " ";
		maxHeap.pop();
	}

	cout << endl << endl;
}

void displayMinHeap(priority_queue<int, vector<int>, greater<int> > minHeap) {
	cout << "Min heap size - " << minHeap.size() << endl; 

	while(!minHeap.empty()) {
		cout << minHeap.top() << " ";
		minHeap.pop();
	}

	cout << endl << endl;
}


int main(int argc, char const *argv[])
{
	// this priority queue sorts in decending order 
	priority_queue<int> maxHeap;

	maxHeap.push(5);
	maxHeap.push(10);
	maxHeap.push(101);
	maxHeap.push(25);
	maxHeap.push(55);
	maxHeap.push(79);
	maxHeap.push(68);

	displayMaxHeap(maxHeap);

	// this priority queue sorts in ascending order 
	priority_queue<int, vector<int>, greater<int> > minHeap;

	minHeap.push(5);
	minHeap.push(10);
	minHeap.push(101);
	minHeap.push(25);
	minHeap.push(55);
	minHeap.push(79);
	minHeap.push(68);

	displayMinHeap(minHeap);
	
	return 0;
}