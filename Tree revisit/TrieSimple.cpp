#include <iostream>
#include <cstring>
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

void Insertion(char* str, int length)
{
	node* travel = root;

	for (int i = 0; i < length; ++i)
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

bool Search(char* str, int length)
{
	node* travel = root;

	for (int i = 0; i < length; ++i)
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

void MakeLower(char* str, int length)
{
	for (int i = 0; i < length; ++i)
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
		char* str;
		cin>>str;

		int length = strlen(str);

		MakeLower(str, length);

		Insertion(str, length);
	}

	cout<<"how many words you want to Search"<<endl;

	cin>>num;

	for (int i = 0; i < num; ++i)
	{
		
		char se_str[15];
		cin>>se_str;

		int length = strlen(se_str);

		MakeLower(se_str, length);

		bool status = Search(se_str, length);

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