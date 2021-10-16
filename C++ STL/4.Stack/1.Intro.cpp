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
	stack<int> lifoList;

	lifoList.push(128);
	lifoList.push(64);
	lifoList.push(32);
	lifoList.push(16);
	lifoList.push(8);
	lifoList.push(4);
	lifoList.push(2);
	lifoList.push(1);
	lifoList.push(101);
	lifoList.push(111);
	lifoList.push(1011);
	
	display(lifoList);

	return 0;
}

/*
	Stacks are special type of data structures

	work type
	LIFO - Last In First Out
*/