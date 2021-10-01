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

	// returns true if vector is empty
	if (arr.empty()) {
		cout << "vector is empty" << endl;
	} else {
		cout << "vector is not empty" << endl;
	}

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

	// returns true if vector is empty
	cout << "after successful insert" << endl;
	if (arr.empty()) {
		cout << "vector is empty" << endl;
	} else {
		cout << "vector is not empty" << endl;
	}

	display(arr);

	// Insert At the begin
	arr.insert(arr.begin(), 7);
	arr.insert(arr.begin(), 5);
	arr.insert(arr.begin(), 9);
	display(arr);

	// Insert at any position
	arr.insert(arr.end()-3, 22);
	arr.insert(arr.end()-3, 25);
	display(arr);

	// Insert n times at specific position
	arr.insert(arr.end()-5, 7, 13);
	display(arr);

	//--------- Accessing Element ---------//
	// Accessing front elment of current vector
	cout << "Front element of current vector is - " << arr.front() << endl;
	display(arr);

	// Accessing last elment of current vector
	cout << "Front element of current vector is - " << arr.back() << endl;
	display(arr);

	// Accessing element with at()
	// It's a direct index access
	cout << arr.at(5) << endl;


	//--------- Reverse Vector ---------//
	// reverse full vector
	cout << "reversing full vector" << endl;
	reverse(arr.begin(), arr.end());
	display(arr);

	// reverse a specific range
	// cout << "reverse a specific range" << endl;
	// reverse(arr.begin() + 2, arr.end() + 5);
	// display(arr);

	//--------- Deletion ---------//
	// removing first element
	cout << "Before Deletion first element" << endl;
	display(arr);
	arr.erase(arr.begin());
	cout << "After Deletion first element" << endl;
	display(arr);

	// removing last element
	cout << "Before Deletion last element" << endl;
	display(arr);
	arr.erase(arr.end()-1);
	// or the below line
	// arr.resize(arr.size() - 1);
	cout << "After Deletion last element" << endl;
	display(arr);

	// removing range of vector element
	cout << "Before Deletion range of vector element" << endl;
	display(arr);
	// arr.erase(arr.begin(), arr.begin() + 4);
	cout << "After Deletion range of vector element" << endl;
	display(arr);

	// removing duplicate elements
	cout << "Before Deletion of removing duplicate elements" << endl;
	display(arr);
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	cout << "After Deletion of removing duplicate elements" << endl;
	display(arr);

	return 0;
}

/*
	Vector is a dynamic array
*/