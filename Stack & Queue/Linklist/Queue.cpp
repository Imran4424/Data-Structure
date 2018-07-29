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

	public: void clear()
	{
		head = NULL;
	}

	public: void push(int value)
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

	public: int pop()
	{
		if (head == NULL)
		{
			count<<"Queue Underflow"<<endl;

			return 0;
		}

		
	}	
};