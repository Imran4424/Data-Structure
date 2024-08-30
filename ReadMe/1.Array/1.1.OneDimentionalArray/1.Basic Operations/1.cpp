/*
	Read and Display:
	Write a program that reads and displays an array.
*/

#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int size;
	cout << "enter the size of the array: ";
	cin >> size;

	// declaring the array
	int arr[size];

	cout << "enter the array elements" << endl;
	for (int i = 0; i < size; ++i) {
		cin >> arr[i];
	}

	// displaying the array elements
	cout << "array elements are: " << endl;
	for (int i = 0; i < size; ++i) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}