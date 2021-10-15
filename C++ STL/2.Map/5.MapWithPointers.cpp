#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

void displayPointer(vector<int> *arr) {
	// size() methods returns the vector size
	for (int i = 0; i < arr -> size(); i++) {
		cout << arr -> at(i) << " ";
	}
	cout << endl << endl;
}

void display(map<string, vector<int>* > mapList, string key) {
	cout << "---------------------------------------" << endl;
	cout << key << " has " << mapList[key] -> size() << " coins" << endl;
	cout << key << "'s coin values are" << endl; 
	displayPointer(mapList[key]);
	cout << "---------------------------------------" << endl;

}

int main(int argc, char const *argv[])
{
	map<string, vector<int>* > coinCollection;

	coinCollection["imran"] = new vector<int>();
	coinCollection["sujan"] = coinCollection["imran"];
	coinCollection["nayeem"] = new vector<int>();
	coinCollection["linkon"] = coinCollection["nayeem"];
	coinCollection["munir"] = new vector<int>();

	coinCollection["imran"] -> push_back(13);
	coinCollection["imran"] -> push_back(26);
	coinCollection["imran"] -> push_back(39);
	coinCollection["imran"] -> push_back(55);
	coinCollection["imran"] -> push_back(65);
	coinCollection["imran"] -> push_back(95);
	coinCollection["imran"] -> push_back(101);

	coinCollection["nayeem"] -> push_back(18);
	coinCollection["nayeem"] -> push_back(36);
	coinCollection["nayeem"] -> push_back(54);
	coinCollection["nayeem"] -> push_back(72);

	coinCollection["munir"] -> push_back(14);
	coinCollection["munir"] -> push_back(28);
	coinCollection["munir"] -> push_back(56);

	display(coinCollection, "imran");
	display(coinCollection, "sujan");
	display(coinCollection, "nayeem");
	display(coinCollection, "linkon");
	display(coinCollection, "munir");

	return 0;
}