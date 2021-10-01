#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
using namespace std;

void display(vector< vector<int> > arr) {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;
}

int main(int argc, char const *argv[])
{
	// declaring 2D dynamic vector
	vector< vector<int> > arr;

	vector<int> rowOne(5, 25);
	vector<int> rowTwo(3, 15);
	vector<int> rowThree(7, 13);

	arr.push_back(rowOne);
	arr.push_back(rowTwo);
	arr.push_back(rowThree);

	display(arr);

	// declaring fixed row sized 2D vector
	vector< vector<int> > fixedRowArr(3);
	// or below code
	// vector<int> fixedRowArr[3];
	fixedRowArr[0] = rowOne;
	fixedRowArr[1] = rowTwo;
	fixedRowArr[2] = rowThree;
	display(fixedRowArr);

	// declaring fixed row and col sized 2D vector
	vector< vector<int> > fixedRowColArr(3, vector<int>(3));

	// another way
	// vector <int> fixedRowColArr[3];
	// for (int i = 0; i < fixedRowColArr.size(); i++) {
	// 	fixedRowColArr[i] = vector<int> (3);
	// }

	srand(time(0));
	for (int i = 0; i < fixedRowColArr.size(); i++) {
		for (int j = 0; j < fixedRowColArr[i].size(); j++) {
			fixedRowColArr[i][j] = rand() % 100 + 10;
		}
	}

	display(fixedRowColArr);

	// declaring fixed row and col sized 2D vector with value
	vector< vector<int> > fixedRowColArrValue(3, vector<int>(3, 13));

	display(fixedRowColArrValue);

	return 0;
}

/*
	2D Vector - 2D Dynamic Array
*/