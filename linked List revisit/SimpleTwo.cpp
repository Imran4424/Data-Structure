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

void delete_at_the_end()
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

void delete_at_the_begin()
{
	if (head == NULL)
	{
		cout<<"Underflow, can't delete"<<endl;

		return;
	}

	head = head -> nextAddress;
}

void delete_at_nth_position(int value)
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

void display()
{
	if (head == NULL)
	{
		cout<<"there's nothing to display"<<endl;

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


	// display the node

	display();

	// delete nodes

	cout<<"how many nodes you want to delete"<<endl;

	int num;
	cin >> num;

	for (int i = 0; i < num; ++i)
	{
		int del_val;
		cin>>del_val;

		//delete_at_the_end();
		delete_at_the_begin();
		//delete_at_nth_position(del_val);
	}

	// display again

	display();

	return 0;
}
