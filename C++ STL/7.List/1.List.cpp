#include <iostream>
#include <list>
using namespace std;

void display(list<int> current) {
	cout << "this list's size is - " << current.size() << endl;

	list <int> :: iterator it;
	for (it = current.begin(); it != current.end(); it++) {
		cout << *it << " ";
	}

	cout << endl << endl;
}

int main(int argc, char const *argv[])
{
	list <int> doublyLinkedList;

	for (int i = 1; i <= 5; i++) {
		doublyLinkedList.push_back(i * 2);
	}

	display(doublyLinkedList);

	for (int i = 1; i <= 5; i++) {
		doublyLinkedList.push_front(i * i);
	}

	return 0;
}


/*
	Lists underlying data structure - Doubly Linked List

	Lists are sequence containers that allow non-contiguous memory allocation. 
	As compared to vector, list has slow traversal, but once a position has been found, 
	insertion and deletion are quick.

	reference - https://www.geeksforgeeks.org/list-cpp-stl/
*/