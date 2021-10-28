#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, string> wordCount;

void displayMaxHeap(priority_queue<wordCount> maxHeap) {
	cout << "Max heap size - " << maxHeap.size() << endl; 

	while(!maxHeap.empty()) {
		cout << maxHeap.top().second << " ";
		maxHeap.pop();
	}

	cout << endl << endl;
}

void displayMinHeap(priority_queue<wordCount, vector<wordCount>, greater<wordCount> > minHeap) {
	cout << "Min heap size - " << minHeap.size() << endl; 

	while(!minHeap.empty()) {
		cout << minHeap.top().second << " ";
		minHeap.pop();
	}

	cout << endl << endl;
}

int main(int argc, char const *argv[])
{
	
	return 0;
}