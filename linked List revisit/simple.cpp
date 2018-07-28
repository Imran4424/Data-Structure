#include <iostream>
using namespace std;

struct node
{
	int data
	node* nextAddress;
};


// the head
node* head;

void insert_node_at_the_end(int info)
{
	node* temp = new node();

	temp->data = info;
	temp->nextAddress = NULL;

	node* travel = head;

	while(travel->nextAddress != NULL)
	{
		travel = travel->nextAddress;
	}

	travel->nextAddress = temp;
}

int main(int argc, char const *argv[])
{
	head = NULL;

	cout<<"how many node's you want to insert"<<endl;

	return 0;
}