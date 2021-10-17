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

	/*----------------------------Insertion Front--------------------------------*/
	for (int i = 1; i <= 5; i++) {
		doublyLinkedList.emplace_back(i * 2);
	}

	cout << "after insertion in back" << endl;
	display(doublyLinkedList);

	/*----------------------------Insertion Back--------------------------------*/
	for (int i = 1; i <= 5; i++) {
		doublyLinkedList.emplace_front(i * i);
	}

	cout << "after insertion in front" << endl;
	display(doublyLinkedList);

	cout << "front of the list is - " << doublyLinkedList.front() << endl;
	cout << "back of the list is - " << doublyLinkedList.back() << endl;

	cout << endl;

	/*----------------------------Insertion Using emplace--------------------------------*/
	// inserting values with emplace method
	// it takes
	// iterator position
	// value
	doublyLinkedList.emplace(doublyLinkedList.begin(), 5);
	doublyLinkedList.emplace(doublyLinkedList.begin(), 7);
	doublyLinkedList.emplace(doublyLinkedList.end(), 9);
	doublyLinkedList.emplace(doublyLinkedList.end(), 12);
	cout << "after inserting in front and back using emplace method" << endl;
	display(doublyLinkedList);

	/*----------------------------Reverse--------------------------------*/
	doublyLinkedList.reverse();
	cout << "after reversing the linked list" << endl;
	display(doublyLinkedList);

	/*----------------------------Sorting--------------------------------*/
	doublyLinkedList.sort();
	cout << "after sorting the linked list" << endl;
	display(doublyLinkedList);

	/*----------------------------Removing in Two sides--------------------------------*/
	
	doublyLinkedList.pop_back();
	cout << "after popping one element from back" << endl;
	display(doublyLinkedList);

	doublyLinkedList.pop_front();
	cout << "after popping one element from front" << endl;
	display(doublyLinkedList);

	return 0;
}


/*
	Lists underlying data structure - Doubly Linked List

	here we are using emplace_front() and emplace_back() 
	instead of 
	push_front() and push_back()
*/