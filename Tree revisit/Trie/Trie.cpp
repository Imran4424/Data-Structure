#include <iostream>
#include <cstring>
using namespace std;

class Trie
{
	private: struct node
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

	private: node* root = new node();

	public: void Insertion(char* str, int length)
	{
		node* travel = root;

		for (int i = 0; i < length; ++i)
		{
			int id = str[i] - 'a';

			if (travel -> next[id] == NULL)
			{
				/* code */
			}
		}
	}
	
};


int main(int argc, char const *argv[])
{
	
	return 0;
}