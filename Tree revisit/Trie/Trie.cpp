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
	
};


int main(int argc, char const *argv[])
{
	
	return 0;
}