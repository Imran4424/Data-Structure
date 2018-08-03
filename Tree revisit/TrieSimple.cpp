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

int main(int argc, char const *argv[])
{
	cout<<"how many words you want to insert"<<endl;

	int num;
	cin>>num;

	cout<<"enter the words"<<endl;

	for (int i = 0; i < num; ++i)
	{
		
	}

	return 0;
}