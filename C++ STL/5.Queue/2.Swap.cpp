#include <iostream>
#include <queue>
using namespace std;

void display(queue<int> current) {
	cout << "size of the current queue is - " << current.size() << endl;

	while(!current.empty()) {
		// returns the front element
		cout << current.front() << " ";

		// returns the tail element
		// cout << current.back() << " ";
		
		current.pop();
	}

	cout << endl;
}

int main(int argc, char const *argv[])
{
	queue<int> listOne;

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

	queue<int> listTwo;

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