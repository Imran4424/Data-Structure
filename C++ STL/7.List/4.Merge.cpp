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

// predicate
// comparator function for list merge
bool ascendingComp(int numOne, int numTwo)
{
    return numOne < numTwo;
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

	/*----------------------------merging the sorted elements of two list--------------------------------*/
	// merging with prior sorting in ascending order
	
	// first sort two list
	listOne.sort();
	listTwo.sort();

	// now merge two list
	listOne.merge(listTwo);
	cout << "after merging two sorted list" << endl;
	cout << "listOne now holds all contents of two list" << endl;
	display(listOne);

	cout << "and list two is empty now" << endl;
	display(listTwo);


	/*-------------------TODO-------------------*/
	// comparator not working
	// fixing the comparator

	// merging with a help of comparator
	// first let's destroy sorted structure
	listOne.insert(listOne.begin(), 3, 101);

	// now copying listOne to listTwo
	listTwo = listOne;

	listOne.merge(listTwo, ascendingComp);
	cout << "after merging two lists with a comparator" << endl;
	cout << "listOne now holds all contents of two list" << endl;
	display(listOne);
	
	return 0;
}