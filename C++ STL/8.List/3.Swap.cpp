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
	list<int> listOne, listTwo;

	/*----------------------------Insertion Back--------------------------------*/
	for (int i = 1; i <= 5; i++) {
		listOne.push_back(i * 2);
	}

	cout << "List One - after insertion in back" << endl;
	display(listOne);

	/*----------------------------Insertion Front--------------------------------*/
	for (int i = 1; i <= 5; i++) {
		listTwo.push_front(i * i);
	}

	cout << "List Two - after insertion in front" << endl;
	display(listTwo);

	// swap the elements of two list
	listOne.swap(listTwo);

	cout << "List one elements after swap" << endl;
	display(listOne);

	cout << "List two elements after swap" << endl;
	display(listTwo);
	
	return 0;
}