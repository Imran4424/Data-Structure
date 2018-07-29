#include <iostream>
using namespace std;

class Stack
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
			cout<<"Stack Underflow"<<endl;

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

	public: int top()
	{
		if (head == NULL)
		{
			cout<<"Stack is empty"<<endl;

			return 0;
		}

		node* travel = head;

		while(travel -> nextAddress != NULL)
		{
			travel = travel -> nextAddress;
		}

		return travel -> data;
	}
	
};


int main(int argc, char const *argv[])
{
	Stack obj;

	return 0;
}