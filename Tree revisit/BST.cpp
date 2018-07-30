#include <iostream>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
};

node* root;

node* GetNewNode(int value)
{
	node* temp = new node();

	temp -> data = value;
	temp -> left = NULL;
	temp -> right = NULL;

	return temp;
}

void InsertNode(node* travel, int value)
{
	if (travel == NULL)
	{
		travel = GetNewNode(value);

		return;
	}
	else if (data < travel -> data)
	{
		InsertNode(travel -> left, value);
	}
	else if (data >= travel -> data)
	{
		InsertNode(travel -> right, value);
	}
}

int main(int argc, char const *argv[])
{
	root = NULL;



	return 0;
}