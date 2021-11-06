#include <iostream>
#include <queue>
#include <vector>
using namespace ::std;

typedef pair<int, int> position;


void display(priority_queue<position, vector<position>, greater<position> > minHeap) {
	cout << "Min Heap Size - " << minHeap.size() << endl; 

	while(!minHeap.empty()) {
		cout << minHeap.top().first << " " << minHeap.top().second << endl;
		minHeap.pop();
	}

	cout << endl;
}

int main(int argc, char const *argv[])
{
	priority_queue<position, vector<position>, greater<position> > minHeap;

	minHeap.push({12, 24});
	minHeap.push({21, 42});
	minHeap.push({55, 30});
	minHeap.push({13, 9});
	minHeap.push({75, 25});
	minHeap.push({17, 5});
	minHeap.push({65, 35});

	display(minHeap);
	
	return 0;
}

/*
	when we try to use priority queue with an pair type

	priority queue will sort the data by the pair's first element

	when no custom comparator is provided

	that means, if we want to sort a list with pair's first element,
	then there is no need to use custom comparator
*/