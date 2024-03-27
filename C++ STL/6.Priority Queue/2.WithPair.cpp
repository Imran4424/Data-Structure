#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, string> rollName;

void displayMaxHeap(priority_queue<rollName> maxHeap) {
	cout << "Max heap size - " << maxHeap.size() << endl; 

	while(!maxHeap.empty()) {
		cout << maxHeap.top().first << " " << maxHeap.top().second << endl;
		maxHeap.pop();
	}

	cout << endl << endl;
}

void displayMinHeap(priority_queue<rollName, vector<rollName>, greater<rollName> > minHeap) {
	cout << "Min heap size - " << minHeap.size() << endl; 

	while(!minHeap.empty()) {
		cout << minHeap.top().first << " " << minHeap.top().second << endl;
		minHeap.pop();
	}

	cout << endl << endl;
}

int main(int argc, char const *argv[])
{
	// this priority queue sorts in decending order
	// in case of pair it sorts according to the first pair
	priority_queue<rollName> maxHeap;
	maxHeap.push(make_pair(13, "Imran"));
	maxHeap.push(make_pair(14, "Munir"));
	maxHeap.push(make_pair(12, "Soad"));
	maxHeap.push(make_pair(17, "Nayeem"));
	maxHeap.push(make_pair(10, "Choyon"));
	maxHeap.push(make_pair(4, "Rasel"));
	maxHeap.push(make_pair(28, "Linkon"));
	maxHeap.push(make_pair(32, "Maliha"));
	maxHeap.push(make_pair(43, "Arongka"));
	maxHeap.push(make_pair(25, "Purba"));
	maxHeap.push(make_pair(23, "Horidas"));

	displayMaxHeap(maxHeap);


	// this priority queue sorts in ascending order 
	// in case of pair it sorts according to the first pair
	priority_queue<rollName, vector<rollName>, greater<rollName> > minHeap;
	minHeap.push(make_pair(13, "Imran"));
	minHeap.push(make_pair(14, "Munir"));
	minHeap.push(make_pair(12, "Soad"));
	minHeap.push(make_pair(17, "Nayeem"));
	minHeap.push(make_pair(10, "Choyon"));
	minHeap.push(make_pair(4, "Rasel"));
	minHeap.push(make_pair(28, "Linkon"));
	minHeap.push(make_pair(32, "Maliha"));
	minHeap.push(make_pair(43, "Arongka"));
	minHeap.push(make_pair(25, "Purba"));
	minHeap.push(make_pair(23, "Horidas"));

	displayMinHeap(minHeap);

	return 0;
}