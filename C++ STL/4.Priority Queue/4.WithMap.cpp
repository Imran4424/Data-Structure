#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

void displayMaxHeap(priority_queue<int> maxHeap) {
	cout << "Max heap size - " << maxHeap.size() << endl; 

	while(!maxHeap.empty()) {
		cout << maxHeap.top() << " ";
		maxHeap.pop();
	}

	cout << endl << endl;
}

void displayHelper(map<string, priority_queue<int> > tempList, string key) {
	cout << key << " keeps" << endl;
	displayMaxHeap(tempList[key]);
}

int main(int argc, char const *argv[])
{
	map<string, priority_queue<int> > maxHeapList;

	maxHeapList["imran"] = priority_queue<int>();
	maxHeapList["sujan"] = priority_queue<int>();
	maxHeapList["nayeem"] = priority_queue<int>();

	// Use current time as seed for random generator
	srand(time(0));
	
	for (int i = 0; i < 5; i++) {
		maxHeapList["imran"].push(rand() % 1000 + 1);
		maxHeapList["sujan"].push(rand() % 1000 + 1);
		maxHeapList["nayeem"].push(rand() % 1000 + 1);
	}

	displayHelper(maxHeapList, "imran");
	displayHelper(maxHeapList, "sujan");
	displayHelper(maxHeapList, "nayeem");

	return 0;
}