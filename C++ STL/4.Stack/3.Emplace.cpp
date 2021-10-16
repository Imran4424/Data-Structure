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

	lifoList.emplace(128);
	lifoList.emplace(64);
	lifoList.emplace(32);
	lifoList.emplace(16);
	lifoList.emplace(8);
	lifoList.emplace(4);
	lifoList.emplace(2);
	lifoList.emplace(1);
	lifoList.emplace(101);
	lifoList.emplace(111);
	lifoList.emplace(1011);
	
	display(lifoList);
	
	return 0;
}

/*
	Stacks are special type of data structures

	work type
	LIFO - Last In First Out

	emplace wrok just like push
*/