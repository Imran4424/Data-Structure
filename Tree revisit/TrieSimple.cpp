#include <iostream>
using namespace std;

struct node
{
	bool endmark;
	node* next[26+1];

	node()
	{
		
	}
};