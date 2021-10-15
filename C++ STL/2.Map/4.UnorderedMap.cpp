#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

void display(unordered_map<string, int> objMap) {
	unordered_map<string, int>::iterator it;

	for(it = objMap.begin(); it != objMap.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}

	cout << endl;
}


int main(int argc, char const *argv[])
{
	// declaration of map
	unordered_map <string, int> baseMap;

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
	Unordered Map Basic

	unsorted map

	Underlying data structure - Hash Table
	Search time - Average - O(1)
		      Worst   - O(n)

	Insertion - Average - O(1)
		    Worst   - O(n)

	Deletetion - Average - O(1)
		     Worst   - O(n)

	Use when,
		You need to keep count of some data (Example – strings) and no ordering is required.
		You need single element access i.e. no traversal.
*/
