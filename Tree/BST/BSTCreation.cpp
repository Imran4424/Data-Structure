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

int MinValue(node* travel)
{
	if (travel -> left == NULL)
	{
		return travel -> data;
	}
	else
	{
		return MinValue(travel -> left);
	}
}


void DeleteNode(node* travel, int value)
{
	// base case
	if (NULL == travel)
	{
		return;
	}

	if (value < travel -> data)
	{
		DeleteNode(travel -> left, value);
	}
	else if(value > travel -> data)
	{
		DeleteNode(travel -> right, value);
	}
	else
	{
		//case one - no child
		if (NULL == travel -> left && NULL == travel -> right)
		{
			travel = NULL;

			return;
		}
		// case two - one child
		else if (NULL == travel -> left)
		{
			travel = travel -> right;
		}
		else if (NULL == travel -> right)
		{
			travel = travel -> left
		}
		else // case three - both child
		{

		}

	}
}