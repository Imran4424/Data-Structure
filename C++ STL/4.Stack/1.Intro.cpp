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

	fifoList.push(128);
	fifoList.push(64);
	fifoList.push(32);
	fifoList.push(16);
	fifoList.push(8);
	fifoList.push(4);
	fifoList.push(2);
	fifoList.push(1);
	fifoList.push(101);
	fifoList.push(111);
	fifoList.push(1011);
	
	display(fifoList);
	
	return 0;
}

/*
	Stacks are special type of data structures

	work type
	FIFO - First In First Out
*/