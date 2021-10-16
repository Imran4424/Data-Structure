#include <iostream>
#include <stack>
using namespace std;

void display(stack<int> current) {
	cout << "size of the current stack is - " << current.size() << endl;

	while(!current.empty()) {
		cout << current.top() << " ";
		current.pop();
	}

	cout << endl;
}

int main(int argc, char const *argv[])
{
	stack<int> fifoList;

	fifoList.emplace(128);
	fifoList.emplace(64);
	fifoList.emplace(32);
	fifoList.emplace(16);
	fifoList.emplace(8);
	fifoList.emplace(4);
	fifoList.emplace(2);
	fifoList.emplace(1);
	fifoList.emplace(101);
	fifoList.emplace(111);
	fifoList.emplace(1011);
	
	display(fifoList);
	
	return 0;
}

/*
	Stacks are special type of data structures

	work type
	FIFO - First In First Out

	emplace wrok just like push
*/