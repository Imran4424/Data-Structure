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

int FindMaxValue(node* travel)
{
	if (NULL == travel -> right)
	{
		return travel -> data;
	}

	return FindMaxValue(travel -> right);
}

int FindMinValue(node* travel)
{
	if (NULL == travel -> left)
	{
		return travel -> data;
	}
	
	return FindMinValue(travel -> left);
}


void DeleteNode(node* travel, int target)
{
	// base case
	if (NULL == travel)
	{
		return;
	}

	if (target < travel -> data)
	{
		DeleteNode(travel -> left, target);
	}
	else if(target > travel -> data)
	{
		DeleteNode(travel -> right, target);
	}
	else
	{
		//case one - no child
		if (NULL == travel -> left && NULL == travel -> right)
		{
			travel = NULL;
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
			int minValue = FindMinValue(travel -> right);

			travel -> data = minValue;

			DeleteNode(travel -> right, minValue);
		}

	}
}

void PreOrder(node* travel)
{
	if (NULL == travel)
	{
		return;
	}

	cout << travel -> data << " ";

	PreOrder(travel -> left);
	PreOrder(travel -> right);
}

void InOrder(node* travel)
{
	if (NULL == travel)
	{
		return;
	}

	InOrder(travel -> left);

	cout << travel -> data << " ";

	InOrder(travel -> right);
}

void PostOrder(node* travel)
{
	if (NULL == travel)
	{
		return;
	}

	PostOrder(travel -> left);

	PostOrder(travel -> right);

	cout << travel -> data << " ";
}

int main(int argc, char const *argv[])
{
	root = NULL;

	cout << "How many nodes you wanna insert?" << endl;
	int num; 
	cin >> num;

	cout << "enter the values" << endl;

	int inputValue;

	for (int i = 0; i < num; ++i)
	{
		cin >> inputValue;

		InsertNode(root, inputValue);
	}

	cout << "Pre Order Traversal: " ;
	PreOrder(root);
	cout << endl << endl;

	cout << "In Order Traversal: " ;
	InOrder(root);
	cout << endl << endl;

	cout << "Post Order Traversal: " ;
	PostOrder(root);
	cout << endl << endl;

	cout << "How many nodes you want to delete" << endl;

	int delNum;
	cin >> delNum;

	cout << "enter the number you want to delete" << endl;

	int target;

	for (int i = 0; i < delNum; ++i)
	{
		cin >> target;

		DeleteNode(target);
	}

	cout << "Pre Order Traversal: " ;
	PreOrder(root);
	cout << endl << endl;

	cout << "In Order Traversal: " ;
	InOrder(root);
	cout << endl << endl;

	cout << "Post Order Traversal: " ;
	PostOrder(root);
	cout << endl << endl;


	return 0;
}