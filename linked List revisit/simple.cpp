#include <iostream>
using namespace std;

struct node
{
	int data;
	node* nextAddress;
};


// the head
node* head;

void insert_node_at_the_end(int value)
{
	node* temp = new node();

	temp -> data = value;
	temp -> nextAddress = NULL;

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

void insert_node_at_the_begin(int value)
{
	node* temp = new node();

	temp -> data = value;
	temp -> nextAddress = head;

	head = temp;
}

void delete_at_the_end()
{
	node* travel = head;

	while(travel -> nextAddress -> nextAddress != NULL)
	{
		travel = travel -> nextAddress;
	}

	travel -> nextAddress = NULL;
}

void display()
{
	node* travel = head;

	while(travel != NULL)
	{
		cout<<travel->data<<" ";

		travel = travel -> nextAddress;
	}

	cout<<endl;
}

int main(int argc, char const *argv[])
{
	head = NULL;

	cout<<"how many node's you want to insert"<<endl;

	int n;
	cin>>n;

	cout<<"enter the value of the node"<<endl;
	
	for (int i = 0; i < n; ++i)
	{

		int temp_val;
		cin>>temp_val;

		//insert_node_at_the_end(temp_val);
		insert_node_at_the_begin(temp_val);
	}

	// display the node

	display();

	return 0;
}