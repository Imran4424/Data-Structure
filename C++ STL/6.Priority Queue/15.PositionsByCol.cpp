#include <iostream>
#include <queue>
#include <vector>
using namespace ::std;

typedef pair<int, int> position;


struct Compare
{
	bool operator()(position &x, position &y) {
		return x.second > y.second;
	}
};

void display(priority_queue<position, vector<position>, Compare > minHeap) {
	cout << "Min Heap Size - " << minHeap.size() << endl; 

	while(!minHeap.empty()) {
		cout << minHeap.top().first << " " << minHeap.top().second << endl;
		minHeap.pop();
	}

	cout << endl;
}

int main(int argc, char const *argv[])
{
	priority_queue<position, vector<position>, Compare > minHeap;

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
	When we populate priority queue with pair and 
	we want to sort the list by second element of the pair

	then we need to put a custom comparator

	cause system default comparator only works for sort by first element of pair cases
*/