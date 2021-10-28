#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class CustomList {
public:
	bool isRef;
	vector<int> notRefList;
	vector<int>* refList;

	CustomList() {
		isRef = false;
		refList = NULL;
	}

	CustomList(vector<int>* list) {
		refList = list;
		isRef = true;
    	}
};

unordered_map<string, CustomList> listDictionary;

void display(vector<int>* vt) {
	for (int i = 0; i < vt->size(); i++) {
		cout << vt->at(i) << " ";
	}

	cout << endl << endl;
}

int main()
{
	listDictionary["Imran"] = CustomList();

	listDictionary["Imran"].notRefList.push_back(2);
	listDictionary["Imran"].notRefList.push_back(4);
	listDictionary["Imran"].notRefList.push_back(8);

	listDictionary["Sujan"] = CustomList(&listDictionary["Imran"].notRefList);

	listDictionary["Sujan"].refList->at(1) = 55;

	display(&listDictionary["Imran"].notRefList);
	display(listDictionary["Sujan"].refList);

	cout << "Hey It's Working" << endl;

    return 0;
}