#include <iostream>
using namespace std;


class Queue
{
		private: struct node
	{
		int data;
		node* nextAddress;
	};

	private: node* head;

	public: Stack()
	{
		head = NULL;
	}

	public: bool IsEmpty()
	{
		if (head == NULL)
		{
			return true;
		}

		return false;
	}

	public: int size()
	{
		if (head == NULL)
		{
			return 0;
		}

		int count = 0;

		node* travel = head;

		while(travel != NULL)
		{
			travel = travel -> nextAddress;

			count++;
		}

		return count;	
	}

	public: void Clear()
	{
		head = NULL;
	}

	public: void Push(int value)
	{
		node* temp = new node();

		temp -> data = value;
		temp -> nextAddress = NULL;

		

		node* travel = head;

		while(travel -> nextAddress != NULL)
		{
			travel = travel -> nextAddress;
		}

		travel -> nextAddress = temp;
	}

	public: void Pop()
	{
		if (head == NULL)
		{
			count<<"Queue Underflow"<<endl;

			return 0;
		}

		head = head -> nextAddress;
	}

	public: int Rear()
	{
		if (head == NULL)
		{
			cout<<"Queue is empty"<<endl;

			return 0;
		}

		node* travel = head;

		while(travel -> nextAddress != NULL)
		{
			travel = travel -> nextAddress;
		}

		return travel -> data;
	}

	public: int Front()
	{
		if (head == NULL)
		{
			cout<<"Queue is empty"<<endl;
		}

		return head -> data;
	}

	public: void Display()
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
	
};