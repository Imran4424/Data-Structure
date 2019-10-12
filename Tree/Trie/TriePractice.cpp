#include <iostream>
#include <string>
using namespace std;

struct node
{
	bool endMark;
	node* next[26 + 1];

	node()
	{
		endMark = false;

		for (int i = 0; i < 27; ++i)
		{
			next[i] = NULL;
		}
	}
};

node* root = new node(); // creating empty node



void Insertion(string word)
{
	node* travel = 
}


string ToLower(string str)
{
	for (int i = 0; i < str.size(); ++i)
	{
		if(str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
	}

	return str;
}

int main(int argc, char const *argv[])
{
	cout << "how many words you want to insert" << endl;

	int numInsert;
	cin >> numInsert;

	for (int i = 0; i < numInsert; ++i)
	{
		string word;
		cin >> word;

		word = ToLower(word);

		Insertion(word);
	}

	return 0;
}