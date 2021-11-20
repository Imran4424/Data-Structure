#include <iostream>
#include <map>
#include <string>
using namespace std;

// custom comparator for sorting the map keys in decending order
struct Compare
{
	bool operator()(int x, int y) {
		// greater than for decending sorting
		return x > y;
	}
};

int main(int argc, char const *argv[])
{
	map<int, string, Compare> myMap;

	myMap[13] = "Imran";
	myMap[12] = "Soad";
	myMap[14] = "Munir";
	myMap[18] = "Nayeem";
	myMap[28] = "Linkon";

	for (auto it = myMap.begin(); it != myMap.end(); it++) {
		cout << it -> first << " " << it -> second << endl;
	} 

	return 0;
}

/*
	Custom comparator map

	https://stackoverflow.com/questions/5733254/how-can-i-create-my-own-comparator-for-a-map
*/