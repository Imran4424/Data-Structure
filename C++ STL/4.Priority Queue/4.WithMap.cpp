#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
using namespace std;

void displayMaxHeap(priority_queue<int> maxHeap) {
	cout << "Max heap size - " << maxHeap.size() << endl; 

	while(!maxHeap.empty()) {
		cout << maxHeap.top() << " ";
		maxHeap.pop();
	}

	cout << endl << endl;
}

int main(int argc, char const *argv[])
{
	map<string, priority_queue<int> > maxHeapList;
	
	return 0;
}