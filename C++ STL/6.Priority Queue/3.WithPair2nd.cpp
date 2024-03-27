#include <iostream>
#include <queue>
using namespace std;

// typedef pair<string, int> NameRoll;

struct NameRoll
{
	string name;
	int roll;

	NameRoll(string name, int  roll) {
		this -> name = name;
		this -> roll = roll;
	}

	// operator overloading for max heap
	bool operator< (const NameRoll& p) const {
		return roll < p.roll;
	}

	// operator overloading for min heap
	bool operator> (const NameRoll& p) const {
		return roll > p.roll;
	}
};


void displayMaxHeap(priority_queue<NameRoll> maxHeap) {
	cout << "Max heap size - " << maxHeap.size() << endl; 

	while(!maxHeap.empty()) {
		cout << maxHeap.top().name << " " << maxHeap.top().roll << endl;
		maxHeap.pop();
	}

	cout << endl << endl;
}

void displayMinHeap(priority_queue<NameRoll, vector<NameRoll>, greater<NameRoll> > minHeap) {
	cout << "Min heap size - " << minHeap.size() << endl; 

	while(!minHeap.empty()) {
		cout << minHeap.top().name << " " << minHeap.top().roll << endl;
		minHeap.pop();
	}

	cout << endl << endl;
}

int main(int argc, char const *argv[])
{
	// this priority queue sorts in decending order
	// in case of pair it sorts according to the second pair 
	priority_queue<NameRoll> maxHeap;
	maxHeap.push(NameRoll("Imran", 13));
	maxHeap.push(NameRoll("Munir", 14));
	maxHeap.push(NameRoll("Soad", 12));
	maxHeap.push(NameRoll("Nayeem", 17));
	maxHeap.push(NameRoll("Choyon", 10));
	maxHeap.push(NameRoll("Rasel", 4));
	maxHeap.push(NameRoll("Linkon", 28));
	maxHeap.push(NameRoll("Maliha", 32));
	maxHeap.push(NameRoll("Arongka", 43));
	maxHeap.push(NameRoll("Purba", 25));
	maxHeap.push(NameRoll("Horidas", 23));

	displayMaxHeap(maxHeap);

	// this priority queue sorts in ascending order 
	// in case of pair it sorts according to the second pair
	priority_queue<NameRoll, vector<NameRoll>, greater<NameRoll> > minHeap;
	minHeap.push(NameRoll("Imran", 13));
	minHeap.push(NameRoll("Munir", 14));
	minHeap.push(NameRoll("Soad", 12));
	minHeap.push(NameRoll("Nayeem", 17));
	minHeap.push(NameRoll("Choyon", 10));
	minHeap.push(NameRoll("Rasel", 4));
	minHeap.push(NameRoll("Linkon", 28));
	minHeap.push(NameRoll("Maliha", 32));
	minHeap.push(NameRoll("Arongka", 43));
	minHeap.push(NameRoll("Purba", 25));
	minHeap.push(NameRoll("Horidas", 23));
	
	displayMinHeap(minHeap);

	return 0;
}