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

node* InsertNode(node* travel, int value)
{
	if (travel == NULL)
	{
		travel = GetNewNode(value);

		//cout<<"I am here: "<<travel -> data<<endl;

		return travel;
	}
	else if (value < travel -> data)
	{
		travel -> left = InsertNode(travel -> left, value);
	}
	else if (value >= travel -> data)
	{
		travel -> right = InsertNode(travel -> right, value);
	}
}

bool Search(node* travel, int value)
{
	
	if (travel == NULL)
	{
		return false;
	}

	if (travel -> data == value)
	{
		return true;
	}
	else if (value < travel -> data)
	{	
		return Search(travel -> left, value);
	}
	else if (value > travel -> data)
	{
		return Search(travel -> right, value);
	}
}

int MaxValue(node* travel)
{
	if (travel -> left == NULL && travel -> right == NULL)
	{
		return travel -> data;
	}
	else if (travel -> right == NULL)
	{
		return MaxValue(travel -> left);
	}
	else
	{
		return MaxValue(travel -> right);
	}
}

int MinValue(node* travel)
{
	
}

bool isRootEmpty(node* root)
{
	if (root == NULL)
	{
		return false;
	}

	return true;
}

int main(int argc, char const *argv[])
{
	root = NULL;

	cout<<"how many values you want to insert"<<endl;

	int num;
	cin>>num;

	for (int i = 0; i < num; ++i)
	{
		int temp_val;
		cin>>temp_val;

		root = InsertNode(root,temp_val);

		/*
			***
			In this commented code,

			I am trying to say that, tree just worked like linkedlist
			
			So, you don't have return the nodes to root if are using it as global varibale like me

			however,
			You need to return for the first time , because, first time root will contain nothing just NULL

			and NULL can't have data or left or right field

			And

			if (travel == NULL)
			{
				travel = GetNewNode(value);

				return travel;
			}

			Here, we also return travel for the same case
			***
		if (i == 0)
		{
			root = InsertNode(root,temp_val);
		}		
		else
		{
			InsertNode(root,temp_val);
		}

		*/

	}

	cout<<"Enter the number you want to Search"<<endl;

	int target;
	cin>>target;

	if (Search(root,target))
	{
		cout<<"target is found"<<endl;
	}
	else
	{
		cout<<"target is not found"<<endl;
	}

	return 0;
}