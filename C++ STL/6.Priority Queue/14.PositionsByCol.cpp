#include <iostream>
#include <queue>
#include <vector>
using namespace ::std;

typedef pair<int, int> position;


struct Compare
{
	bool operator()(position &x, position &y) {
		return x.second < y.second;
	}
};

void display(priority_queue<position, vector<position>, Compare > maxHeap) {
	cout << "Max Heap Size - " << maxHeap.size() << endl; 

	while(!maxHeap.empty()) {
		cout << maxHeap.top().first << " " << maxHeap.top().second << endl;
		maxHeap.pop();
	}

	cout << endl;
}

int main(int argc, char const *argv[])
{
	priority_queue<position, vector<position>, Compare > maxHeap;

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
	When we populate priority queue with pair and 
	we want to sort the list by second element of the pair

	then we need to put a custom comparator

	cause system default comparator only works for sort by first element of pair cases
*/