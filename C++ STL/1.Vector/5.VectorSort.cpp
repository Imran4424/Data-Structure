#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
using namespace std;

// custom method
bool compareFunc(int a, int b) {
	return a > b;
}

// custom struct
// Binary predicate
struct comp
{
    template<typename T>
    bool operator()(const T &a, const T &b) const {
        return a > b;
    }
};

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

	// Use current time as seed for random generator
	srand(time(0));
	while(n--) {
		int num = rand() % 1000 + 1;
		// insert at the end
		arr.push_back(num);
	}

	display(arr);

	// sorting the elements of vector using
	// asceding order
	sort(arr.begin(), arr.end());
	display(arr);

	// sorting the elements of vector using
	// desceding order
	// using reverse iterator
	cout << "desceding using reverse iterator" << endl;
	sort(arr.rbegin(), arr.rend());
	display(arr);

	// sorting the elements of vector using
	// desceding order
	// using reverse iterator
	cout << "desceding using reverse method provide by algorithm" << endl;
	sort(arr.begin(), arr.end());
	reverse(arr.begin(), arr.end());
	display(arr);

	// sorting the elements of vector using
	// desceding order
	// using std comparator
	cout << "desceding using comparator provide by std" << endl;
	sort(arr.begin(), arr.end(), greater<int>());
	display(arr);

	// sorting the elements of vector using
	// desceding order
	// using custom method
	cout << "desceding using custom func" << endl;
	sort(arr.begin(), arr.end(), compareFunc);
	display(arr);

	// sorting the elements of vector using
	// desceding order
	// using custom struct
	cout << "desceding using custom struct" << endl;
	sort(arr.begin(), arr.end(), comp());
	display(arr);

	return 0;
}

/*
	Vector is a dynamic array
	Vector sort
*/