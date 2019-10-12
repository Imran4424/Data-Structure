#include <iostream>
#include <string>
using namespace std;

struct node
{
	bool endmark;
	node* next[26+1];

	node()
	{
		endmark = false;

		for (int i = 0; i < 27; ++i)
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

void del(node* travel)
{
	for (int i = 0; i < 27; ++i)
	{
		if (travel -> next[i])
		{
			del(travel -> next[i]);
		}
	}

	delete(travel);
}

void MakeLower(string str)
{
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
 		}
	}
}

int main(int argc, char const *argv[])
{
	cout<<"how many words you want to insert"<<endl;

	int num;
	cin>>num;

	cout<<"enter the words"<<endl;

	for (int i = 0; i < num; ++i)
	{
		string str;
		cin >> str;

		MakeLower(str);

		cout << str << endl;

		Insertion(str);
	}

	cout<<"how many words you want to Search"<<endl;

	cin>>num;

	for (int i = 0; i < num; ++i)
	{
		
		string str;
		cin>>str;

		MakeLower(str);

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