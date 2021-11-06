#include <iostream>
#include <queue>
#include <vector>
using namespace ::std;

typedef pair<int, int> position;


void display(priority_queue<position> maxHeap) {
	cout << "Max Heap Size - " << maxHeap.size() << endl; 

	while(!maxHeap.empty()) {
		cout << maxHeap.top().first << " " << maxHeap.top().second << endl;
		maxHeap.pop();
	}

	cout << endl;
}

int main(int argc, char const *argv[])
{
	priority_queue<position> maxHeap;

	maxHeap.push({12, 24});
	maxHeap.push({21, 42});
	maxHeap.push({55, 30});
	maxHeap.push({13, 9});
	maxHeap.push({75, 25});
	maxHeap.push({17, 5});
	maxHeap.push({65, 35});

	display(maxHeap);
	
	return 0;
}

/*
	when we try to use priority queue with an pair type

	priority queue will sort the data by the pair's first element

	when no custom comparator is provided

	that means, if we want to sort a list with pair's first element,
	then there is no need to use custom comparator
*/