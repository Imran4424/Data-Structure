#include <iostream>
#include <set>
using namespace std;

void display(set<int> uSet) {
	set<int>:: iterator it;

	for (it = uSet.begin(); it != uSet.end(); it++) {
		cout << *it << " ";
	}

	cout << endl;
}

int main(int argc, char const *argv[])
{
	// sorted in ascening order
	set<int> unique;

	unique.insert(5);
	unique.insert(5);
	unique.insert(25);
	unique.insert(3);
	unique.insert(2);
	unique.insert(55);
	unique.insert(101);
	unique.insert(55);

	display(unique);

	return 0;
}