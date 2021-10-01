#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <pair>
using namespace std;

void display(map<string, int> objMap) {
	map<string, int>::iterator it;

	for(it = objMap.begin(); it != objMap.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
}

int main(int argc, char const *argv[])
{
	// declaration of map
	map <string, int> baseMap;

	//Insertion
	baseMap.insert(make_pair("Imran", 13));
	baseMap.insert(make_pair("Munir", 14));
	// or
	baseMap["Nayeem"] = 17;

	display(baseMap);

	return 0;
}