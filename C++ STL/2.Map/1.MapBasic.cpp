#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

void display(map<string, int> objMap) {
	map<string, int>::iterator it;

	for(it = objMap.begin(); it != objMap.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}

	cout << endl;
}

int main(int argc, char const *argv[])
{
	// declaration of map
	map <string, int> baseMap;

	//Insertion
	baseMap.insert(pair<string, int> ("Linkon", 28));
	baseMap.insert(make_pair("Imran", 13));
	baseMap.insert(make_pair("Munir", 14));
	// or easier one
	baseMap["Nayeem"] = 17;

	display(baseMap);

	// Access
	cout << "For key Imran, value is - " << baseMap.at("Imran") << endl;
	cout << "For key Linkon, value is - " << baseMap["Linkon"] << endl;

	// Modify Elements
	baseMap.at("Imran") = 393;
	baseMap["Nayeem"] = 115;
	baseMap["Linkon"]++;

	display(baseMap);

	return 0;
}

/*
	Map Basic

	Underlying data structure - Self balancing BST  Red black tree
	Search time - log(n)
	Insertion - log(n) + Rebalance
	Deletetion - log(n) + Rebalance


	Use when,
		You need ordered data.
		You would have to print/access the data (in sorted order).
		You need predecessor/successor of elements.
		https://www.geeksforgeeks.org/advantages-of-bst-over-hash-table/
*/