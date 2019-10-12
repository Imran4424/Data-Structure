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
	node* travel = root;

	for (int i = 0; i < word.size(); ++i)
	{
		int letter = word[i] - 'a';

		if (NULL == travel -> next[letter])
		{
			travel -> next[letter] = new node();
		}

		travel = travel -> next[letter];
	}

	// marking the last letter as word ending
	travel -> endMark = true;
}

bool Search(string word)
{
	node* travel = root;

	for (int i = 0; i < word.size(); ++i)
	{
		int letter = word[i] - 'a';

		if(NULL == travel -> next[letter])
		{
			return false;
		}
	}

	return travel -> endMark;
}

// for deleting the whole tree
void DeleteAll()
{
	node* travel = root;

	for (int i = 0; i < 27; ++i)
	{
		if (NULL != travel -> next[i])
		{
			DeleteAll(travel -> next[i]);
		}
	}

	delete(travel);
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