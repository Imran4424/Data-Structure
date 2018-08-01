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