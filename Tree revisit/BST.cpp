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

		cout<<"I am here: "<<travel -> data<<endl;


		return;
	}
	else if (value < travel -> data)
	{
		InsertNode(travel -> left, value);
	}
	else if (value >= travel -> data)
	{
		InsertNode(travel -> right, value);
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

		cout<<"I am here: "<<travel -> data<<endl;
	}
	else if (value < travel -> data)
	{
		cout<<"I am here: "<<travel -> data<<endl;
		return Search(travel -> left, value);
	}
	else if (value > travel -> data)
	{
		cout<<"I am here: "<<travel -> data<<endl;
		return Search(travel -> right, value);
	}
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

		InsertNode(root,temp_val);
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