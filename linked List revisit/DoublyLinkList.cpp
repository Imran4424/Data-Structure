#include <iostream>
using namespace std;

class DoublyLinkList
{
	private: struct node
	{
		int data;
		node* prevAddress;
		node* nextAddress;
	};

	private node* head;

	public: DoublyLinkList()
	{
		head = NULL;
	}

	public: void InsertAtEnd(int value)
	{
		node* temp = new node();

		temp -> data = value;
		temp -> nextAddress = NULL;

		if (head == NULL)
		{
			temp -> prevAddress = NULL;

			head = temp;

			return;
		}

		node* travel = head;

		while(travel -> nextAddress != NULL)
		{
			travel = travel -> NULL;
		}

		temp -> prevAddress = travel;
		travel -> nextAddress = temp;
	}

	public InsertAtBegin(int value)
	{

	}

	
};