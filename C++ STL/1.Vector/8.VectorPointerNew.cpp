#include <iostream>
#include <vector>
using namespace std;

void displayPointer(vector<int> *arr) {
	// size() methods returns the vector size
	for (int i = 0; i < arr -> size(); i++) {
		cout << arr -> at(i) << " ";
	}
	cout << endl << endl;
}

int main(int argc, char const *argv[])
{
	vector<int>* arr = new vector<int>();

	arr -> push_back(3);
	arr -> push_back(7);
	arr -> push_back(12);
	arr -> push_back(25);
	arr -> push_back(72);
	arr -> push_back(97);
	arr -> push_back(77);
	arr -> push_back(101);

	displayPointer(arr);

	return 0;
}


/*
	Here, we are declaring vector pointer and assigning the vector pointer object with new keyword

	but there are two ways we can declare an object for vector pointer with new keyword

	one,
	vector<int> *arr = new vector<int>();

	two,
	vector<int> *arr = new vector<int>;


	I am choosing one for two reasons,

	1. It looks nice and cleaner
	2. first one matches with other language's syntax of using new keyword, for example java.
	   For a programmer's point of view, it will easier to code, while using multiple languages if they
	   have some similarities.
*/