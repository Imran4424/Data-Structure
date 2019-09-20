#include <iostream>
using namespace std;

struct node
{
	int data;
	node* nextAddress;

	node() {}

	node(int value)
	{
		data = value;
		nextAddress = NULL;
	}
};


// the head
node* head;

void InsertAtEnd(int value)
{
	node* temp = new node(value);

	if (head == NULL)
	{
		head = temp;

		return;
	}

	node* travel = head;

	while(travel -> nextAddress != NULL)
	{
		travel = travel -> nextAddress;
	}

	travel -> nextAddress = temp;
}

void InsertAtBegin(int value)
{
	node* temp = new node(value);

	temp -> nextAddress = head;

	head = temp;
}

void InsertAtNthPosition(int value, int target)
{
	node* temp = new node(value);

	node* travel = head;

	while(travel -> data != target)
	{
		travel = travel -> nextAddress;
	}

	if (travel -> nextAddress != NULL)
	{
		temp -> nextAddress = travel -> nextAddress;

		travel -> nextAddress = temp;
		
	}
	else
	{
		temp -> nextAddress = NULL;

		travel -> nextAddress = temp;
	}

}

void DeleteAtEnd()
{
	if (head == NULL)
	{
		cout<<"Underflow, can't delete"<<endl;

		return;
	}
	else if (head -> nextAddress == NULL)
	{
		head = NULL;

		return;
	}


	node* travel = head;

	while(travel -> nextAddress -> nextAddress != NULL)
	{
		travel = travel -> nextAddress;
	}

	travel -> nextAddress = NULL;
}

void DeleteAtBegin()
{
	if (head == NULL)
	{
		cout<<"Underflow, can't delete"<<endl;

		return;
	}

	head = head -> nextAddress;
}

void DeleteAtNthPositionByValue(int value)
{
	if (head == NULL)
	{
		cout<<"Underflow, can't delete"<<endl;

		return;
	}

	node* travel = head;

	if (travel -> data == value)
	{
		head = travel -> nextAddress;

		return;
	}

	while(travel -> nextAddress -> data != value && travel -> nextAddress != NULL)
	{
		travel = travel -> nextAddress;
	}

	if(travel -> nextAddress -> data == value)
	{
		if (travel -> nextAddress -> nextAddress != NULL)
		{
			
			travel -> nextAddress = travel -> nextAddress -> nextAddress;
		}
		else
		{
			travel -> nextAddress = NULL;
		}		
	}


}

void Display()
{
	if (head == NULL)
	{
		cout<<"there's nothing to Display"<<endl;

		return;
	}

	node* travel = head;

	while(travel != NULL)
	{
		cout<<travel -> data<<" ";

		travel = travel -> nextAddress;
	}

	cout<<endl;
}

int main(int argc, char const *argv[])
{
	head = NULL;

	// insert

	cout<<"how many node's you want to insert"<<endl;

	int n;
	cin>>n;

	cout<<"enter the value of the node"<<endl;
	
	for (int i = 0; i < n; ++i)
	{

		int temp_val;
		cin>>temp_val;

		InsertAtEnd(temp_val);
		//InsertAtBegin(temp_val);
	}


	// Display the node

	Display();

	// delete nodes

	cout<<"how many nodes you want to delete"<<endl;

	int num;
	cin >> num;

	for (int i = 0; i < num; ++i)
	{
		int del_val;
		cin>>del_val;

		//DeleteAtEnd();
		DeleteAtBegin();
		//DeleteAtNthPositionByValue(del_val);
	}

	// Display again

	Display();

	return 0;
}
