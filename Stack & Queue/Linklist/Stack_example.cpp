#include <iostream>
#include <string>
using namespace std;

template <class anyType>
class Stack
{
	private: struct node
	{
		anyType data;
		node* nextAddress;
	};

	private: node* head;

	public: Stack()
	{
		head = NULL;
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

	public: void Push(anyType value)
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

	public: anyType Top()
	{
		if (head == NULL)
		{
			cout<<"Stack is empty"<<endl;

			return NULL;
		}

		node* travel = head;

		while(travel -> nextAddress != NULL)
		{
			travel = travel -> nextAddress;
		}

		return travel -> data;
	}

	
};


struct Student
{
	int id;
	string name;
};

int main(int argc, char const *argv[])
{
	Stack <Student> obj;

	return 0;
}