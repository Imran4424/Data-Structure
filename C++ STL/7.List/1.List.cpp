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

	// insertion in front
	for (int i = 1; i <= 5; i++) {
		doublyLinkedList.push_back(i * 2);
	}

	cout << "after insertion in back" << endl;
	display(doublyLinkedList);

	// insertion in back
	for (int i = 1; i <= 5; i++) {
		doublyLinkedList.push_front(i * i);
	}

	cout << "after insertion in front" << endl;
	display(doublyLinkedList);

	cout << "front of the list is - " << doublyLinkedList.front() << endl;
	cout << "back of the list is - " << doublyLinkedList.back() << endl;

	cout << endl;

	// reversing the list
	doublyLinkedList.reverse();
	cout << "after reversing the linked list" << endl;
	display(doublyLinkedList);

	// sorting the list
	doublyLinkedList.sort();
	cout << "after sorting the linked list" << endl;
	display(doublyLinkedList);


	doublyLinkedList.pop_back();
	cout << "after popping one element from back" << endl;
	display(doublyLinkedList);

	doublyLinkedList.pop_front();
	cout << "after popping one element from front" << endl;
	display(doublyLinkedList);


	// removing duplicate elements of the list
	doublyLinkedList.unique();
	cout << "after removing all duplicate elements" << endl;
	display(doublyLinkedList);

	// it takes
	// iterator position
	// occurence count of values, this can be ignored if count is 1
	// value
	doublyLinkedList.insert(doublyLinkedList.begin(), 5);
	doublyLinkedList.insert(doublyLinkedList.begin(), 7);
	doublyLinkedList.insert(doublyLinkedList.begin(), 3, 55);
	doublyLinkedList.insert(doublyLinkedList.end(), 9);
	doublyLinkedList.insert(doublyLinkedList.end(), 12);
	doublyLinkedList.insert(doublyLinkedList.end(), 3, 55);
	cout << "after inserting in front and back using insert method" << endl;
	display(doublyLinkedList);

	// deletion of list
	// remove method removes all copies of given data
	doublyLinkedList.remove(55);
	cout << "after removing all 55 from list" << endl;
	display(doublyLinkedList);


	// when you try to insert values using assign
	// firstly assign remove all elemnets from list
	// then insert the desired values
	doublyLinkedList.assign(5, 25);
	cout << "after value insertion using assign" << endl;
	display(doublyLinkedList);

	
	// using assign we can also copy the elements from one list to another list
	list<int> copyList;

	// first hand operand is the the list where we will copy the values
	// then secondly we will use an iterator of the list from which we will copy the values
	copyList.assign(doublyLinkedList.begin(), doublyLinkedList.end());
	cout << "after copy main list" << endl;
	display(doublyLinkedList);
	cout << "after copy copied list" << endl;
	display(copyList);


	// removing all elements of list
	doublyLinkedList.clear();
	cout << "after removing all elements" << endl;
	display(doublyLinkedList);
	
	for (int i = 1; i <= 5; i++) {
		doublyLinkedList.push_front(i * i);
	}

	// when we want to copy a list in reverse order
	// we can use reverse iterator 
	// rbegin(), rend() instead of begin(), end()
	copyList.assign(doublyLinkedList.rbegin(), doublyLinkedList.rend());
	cout << "after copying in reverse order" << endl;
	cout << "after copy main list" << endl;
	display(doublyLinkedList);
	cout << "after copy copied list" << endl;
	display(copyList);

	return 0;
}	


/*
	Lists underlying data structure - Doubly Linked List

	Lists are sequence containers that allow non-contiguous memory allocation. 
	As compared to vector, list has slow traversal, but once a position has been found, 
	insertion and deletion are quick.
*/