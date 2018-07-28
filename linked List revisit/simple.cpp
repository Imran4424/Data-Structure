#include <iostream>
using namespace std;

struct node
{
	int data
	node* nextAddress;
};


node* head;

void insert_node_at_the_end(int info)
{
	node* temp;

	temp->data = info;
	temp->nextAddress = NULL;

	node* travel = head;

	while(head->nextAddress != NULL)
	{
		travel = travel->nextAddress;
	}
}

int main(int argc, char const *argv[])
{
	head = NULL;

	return 0;
}