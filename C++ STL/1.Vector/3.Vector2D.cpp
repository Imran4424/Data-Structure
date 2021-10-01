#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void display(vector<vector<int>> arr) {
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
	vector<vector<int>> arr;

	vector<int> rowOne(5, 25);
	vector<int> rowTwo(3, 15);
	vector<int> rowThree(7, 13);

	arr.push_back(rowOne);
	arr.push_back(rowTwo);
	arr.push_back(rowThree);

	display(arr);
	
	return 0;
}

/*
	2D Vector - 2D Dynamic Array
*/