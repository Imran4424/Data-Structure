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

	public: void InsertAtBegin(int value)
	{
		node* temp = new node();

		temp -> data = value;
		temp -> prevAddress = NULL;

		if (head == NULL)
		{
			temp -> nextAddress = NULL;
			head == temp;

			return;
		}

		temp -> nextAddress = head;

		head = temp;

	}

	public: void DeleteAtEnd()
	{
		if (head == NULL)
		{
			return;
		}

		node* travel = head;


		while(travel -> nextAddress -> nextAddress != NULL)
		{
			travel = travel -> nextAddress;
		}

		travel -> nextAddress = NULL;
	}

	public: void DeleteAtBegin()
	{
		if (head == NULL)
		{
			return;
		}

		head = head -> nextAddress;

		head -> prevAddress = NULL;
	}


	public: void ReverseIterative()
	{
		if (head == NULL)
		{
			return;
		}

		node *travel, *temp;

		travel = head;

		while(travel != NULL)
		{
			temp = travel -> prevAddress;
			travel -> prevAddress = travel -> nextAddress;
			travel -> nextAddress = temp

			travel = travel -> prevAddress;
		}

		head = travel;
	}

	public: void ReverseRecursion(node* travel)
	{
		if (travel == NULL)
		{
			head = travel;
		}
	}

	public: void Display()
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

	
};