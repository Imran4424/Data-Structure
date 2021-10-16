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
	stack<int> listOne;

	listOne.push(128);
	listOne.push(64);
	listOne.push(32);
	listOne.push(16);
	listOne.push(8);
	listOne.push(4);
	listOne.push(2);
	listOne.push(1);
	listOne.push(101);
	listOne.push(111);
	listOne.push(1011);

	stack<int> listTwo;

	listTwo.push(1);
	listTwo.push(2);
	listTwo.push(4);
	listTwo.push(8);
	listTwo.push(16);
	listTwo.push(32);
	listTwo.push(64);

	display(listOne);
	display(listTwo);

	cout << "--------------------------------------" << endl;

	listOne.swap(listTwo);

	display(listOne);
	display(listTwo);

	return 0;
}