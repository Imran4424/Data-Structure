#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
using namespace std;

void display(vector<int> arr) {
	// size() methods returns the vector size
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl << endl;
}

int main(int argc, char const *argv[])
{
	// dynamic vector declaration
	vector <int> arr;

	int n;
	cout << "enter your array size" << endl;
	cin >> n;

	//--------- Insertion ---------//
	// Use current time as seed for random generator
	srand(time(0));
	while(n--) {
		int num = rand() % 1000 + 1;
		// insert at the end
		arr.push_back(num);
	}

	display(arr);


	// declaring uninitialized sized vector
	vector<int> uArr(10);
	cout << "before value assign" << endl;
	display(uArr);
	for (int i = 0; i < 10; i++) {
		uArr[i] = rand() % 1000 + 1;
	}
	cout << "after value assign" << endl;
	display(uArr);

	// declaring sized vector with value
	vector<int> initArr(10, 13);
	display(initArr);

	// warning - only available with c++11
	// declaring and init with values
	// vector<int> mark{ 10, 20, 30, 50, 60 };
	// display(mark);

	// init vector with another object
	vector<int> newArrOne = arr;
	cout << "Old vector" << endl;
	display(arr);
	cout << "New vector one" << endl;
	display(newArrOne);

	vector<int> newArrTwo(arr);
	cout << "Old vector" << endl;
	display(arr);
	cout << "New vector two" << endl;
	display(newArrTwo);


	// coparing two vectors is really easy
	// it just use == operator
	if (arr == newArrOne) {
		cout << "Both arr and newArrOne vectors are equal" << endl;
	} else {
		cout << "Both vectors are not equal" << endl;
	}

	return 0;
}

/*
	vector is a dynamic array
	vector initialization
*/