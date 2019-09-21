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

node* root;

void InsertNode(node* travel, int value)
{
	//base case
	if (NULL == travel)
	{
		travel = new node(value);
	}

	if (value < travel -> data)
	{
		InsertNode(travel -> left, value);
	}
	else
	{
		InsertNode(travel -> right, value);
	}
}

void Delete(node* travel, int value)
{
	// base case
	if (NULL == travel)
	{
		return;
	}

	
}