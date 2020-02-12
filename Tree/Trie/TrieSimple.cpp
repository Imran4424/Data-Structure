#include <iostream>
#include <string>
using namespace std;

/*
	Trie Implementation in C++
*/

struct node
{
	bool endmark;
	node* next[26];

	node()
	{
		endmark = false;

		for (int i = 0; i < 26; ++i)
		{
			next[i] = NULL;
		}
	}
};

node* root = new node();

void Insertion(string str)
{
	node* travel = root;

	for (int i = 0; i < str.size(); ++i)
	{
		int id = str[i] - 'a';

		if (travel -> next[id] == NULL)
		{
			travel -> next[id] = new node();
		}

		travel = travel -> next[id];
	}

	travel -> endmark = true;
}

bool Search(string str)
{
	node* travel = root;

	for (int i = 0; i < str.size(); ++i)
	{
		int id = str[i] - 'a';

		if (travel -> next[id] == NULL)
		{
			return false;
		}

		travel = travel -> next[id];
	}

	return travel -> endmark;
}

// for deleting all nodes to free memory
void DeleteAll(node* travel)
{
	for (int i = 0; i < 26; ++i)
	{
		if (travel -> next[i])
		{
			DeleteAll(travel -> next[i]);
		}
	}

	delete(travel);
}

string MakeLower(string str)
{
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
 		}
	}

	return str;
}

void displayTrie(node* travel, string word) {
	if(NULL == travel) {
		return;
	}

	if(travel -> endmark) {
		cout << word << endl;
	}

	for(int i = 0; i < 26; i++) {
		// storing the data 
		string medium = word;

		if(travel -> next[i]) {
			
			medium += (i + 'a');
			displayTrie(travel -> next[i], medium);
		}
	}
}

int main(int argc, char const *argv[])
{

	cout<<"how many words you want to insert"<<endl;

	int num;
	cin >> num;

	cout<<"enter the words"<<endl;

	for (int i = 0; i < num; i++)
	{
		string str;
		cin >> str;

		str = MakeLower(str);

		Insertion(str);
	}

	cout << "--------------------------------" << endl;
	displayTrie(root, "");

	cout<<"how many words you want to Search"<<endl;

	cin>>num;

	for (int i = 0; i < num; ++i)
	{
		
		string str;
		cin >> str;

		str = MakeLower(str);

		bool status = Search(str);

		if (status)
		{
			cout<<"the word is present in the tree"<<endl;
		}
		else
		{
			cout<<"The word is not present in the tree"<<endl;
		}
	}

	return 0;
}