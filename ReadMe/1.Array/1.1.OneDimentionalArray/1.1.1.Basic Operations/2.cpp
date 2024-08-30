/*
	Sum of Elements:
	Write a program that reads an array and displays the sum of its elements.
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

	// calculating the sum
	int sum = 0;
	for (int i = 0; i < size; ++i) {
		sum += arr[i];
	}

	cout << "sum of the elements are: " << sum << endl;

	return 0;
}