#include <iostream>
#include <vector>
using namespace std;

void display(vector<int> &arr) {
	// size() methods returns the vector size
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl << endl;
}

int main(int argc, char const *argv[])
{
	vector<int> arr;
	arr.push_back(3);
	arr.push_back(7);
	arr.push_back(12);
	arr.push_back(25);
	arr.push_back(72);
	arr.push_back(97);
	arr.push_back(77);
	arr.push_back(101);

	vector<int> copyValue = arr;
	vector<int> &copyRef = arr;

	cout << "-------------Before changes--------------" << endl;
	cout << "------- original arr -------" <<endl;
	display(arr);
	cout << "------- value copy arr -------" <<endl;
	display(copyValue);
	cout << "------- reference copy arr -------" <<endl;
	display(copyRef);

	copyValue[3]++;
	copyValue[4] = copyValue[3];

	copyRef[0] = 55;
	copyRef[1] = 55;
	copyRef[2] = 55;

	cout << "-------------After changes--------------" << endl;
	cout << "------- original arr -------" <<endl;
	display(arr);
	cout << "------- value copy arr -------" <<endl;
	display(copyValue);
	cout << "------- reference copy arr -------" <<endl;
	display(copyRef);  

	return 0;
}