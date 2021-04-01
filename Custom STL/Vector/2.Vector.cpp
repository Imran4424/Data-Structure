#include <iostream>
using namespace std;

template <typename Any>
class VectorClass
{
	struct node
	{
		Any data;
		node* next;
		node* prev;

		node() { }

		node(Any data) {
			this -> data = data;
			next = NULL;
			prev = NULL;
		}
	};

	node *head, *tail;
	int current;

public:
	VectorClass() {
		current = 0;
		head = NULL;
		tail = NULL;
	}

	void pushBack(Any data) {
		node* temp = new node(data);
		
		// no element
		if(NULL == tail && NULL == head) {
			head = temp;
			tail = temp;
		} else {
			// at least one element
			temp -> prev = tail;
			tail -> next = temp;
			tail = temp;
		}

		current++;
	}

	void pushFront(Any data) {
		node* temp = new node(data);

		// no element
		if(NULL == tail && NULL == head) {
			head = temp;
			tail = temp;
		} else {
			// at least one element
			temp -> next = head;
			head -> prev = temp;
			head = temp;
		}

		current++;
	}

	void popBack() {
		// no element
		if(NULL == tail && NULL == head) {
			cout << "Stack Underflow" << endl;
			return;
		}

		// only one element
		if (head == tail) {
			head = NULL;
			tail = NULL;
		} else {
			// more than one element
			tail = tail -> prev;
			tail -> next = NULL;
		}

		current--;
	}

	void popFront() {
		// no element
		if(NULL == tail && NULL == head) {
			cout << "Stack Underflow" << endl;
			return;
		}

		// only one element
		if (head == tail) {
			head = NULL;
			tail = NULL;
		} else {
			// more than one element
			head = head -> next;
			head -> prev = NULL;
		}

		current--;
	}

	Any front() {
		if(NULL == head) {
			return head;
		}

		return head -> data;
	}

	Any back() {
		if(NULL == tail) {
			return tail;
		}

		return tail -> data;
	}

	int size() {
		return current;
	}

	void clear() {
		head = NULL;
		tail = NULL;
		current = 0;
	}

	void display() {
		node* travel = head;

		while(NULL != travel) {
			cout << travel -> data << " ";
			travel = travel -> next; 
		}

		cout << endl;
	}
};

int main(int argc, char const *argv[])
{
	VectorClass <int> myVector;

	myVector.pushBack(52);
	myVector.pushFront(22);
	myVector.pushBack(13);
	myVector.pushFront(27);
	myVector.pushBack(72);

	cout << "Vector size is: " << myVector.size() << endl;

	cout << "Vector elements" << endl;
	myVector.display();

	myVector.popBack();
	myVector.popFront();

	cout << "Vector size is: " << myVector.size() << endl;

	cout << "Vector elements" << endl;
	myVector.display();

	return 0;
}