#include <iostream>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;

	node() {} // default constructor

	node(int value)
	{
		data = value;
		left = NULL;
		right = NULL;
	}
};

