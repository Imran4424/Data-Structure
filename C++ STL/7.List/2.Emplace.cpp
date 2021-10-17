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
		doublyLinkedList.emplace_back(i * 2);
	}

	cout << "after insertion in back" << endl;
	display(doublyLinkedList);

	for (int i = 1; i <= 5; i++) {
		doublyLinkedList.emplace_front(i * i);
	}

	cout << "after insertion in front" << endl;
	display(doublyLinkedList);

	cout << "front of the list is - " << doublyLinkedList.front() << endl;
	cout << "back of the list is - " << doublyLinkedList.back() << endl;

	cout << endl;

	doublyLinkedList.reverse();
	cout << "after reversing the linked list" << endl;
	display(doublyLinkedList);

	doublyLinkedList.sort();
	cout << "after sorting the linked list" << endl;
	display(doublyLinkedList);


	doublyLinkedList.pop_back();
	cout << "after popping one element from back" << endl;
	display(doublyLinkedList);

	doublyLinkedList.pop_front();
	cout << "after popping one element from front" << endl;
	display(doublyLinkedList);


	doublyLinkedList.unique();
	cout << "after removing all duplicate elements" << endl;
	display(doublyLinkedList);

	return 0;
}


/*
	Lists underlying data structure - Doubly Linked List

	here we are using emplace_front() and emplace_back() 
	instead of 
	push_front() and push_back()
*/