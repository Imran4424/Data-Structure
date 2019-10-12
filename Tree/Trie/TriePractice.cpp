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

	return 0;
}