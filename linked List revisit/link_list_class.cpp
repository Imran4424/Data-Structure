#include <iostream>
using namespace std;

class Link_list
{
public:
	struct node
	{
		int data;
		node* nextAddress;
	};

	node* head;

	Link_list()
	{
		head = NULL;
	}

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


};




int main(int argc, char const *argv[])
{
	
	return 0;
}