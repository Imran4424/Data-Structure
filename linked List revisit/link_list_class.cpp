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

	void delete_at_the_end()
	{
		if (head == NULL)
		{
			cout<<"Underflow, can't delete"<<endl;

			return;
		}
		else if (head -> nextAddress = NULL)
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

};




int main(int argc, char const *argv[])
{
	Link_list obj = new Link_list();

	

	return 0;
}