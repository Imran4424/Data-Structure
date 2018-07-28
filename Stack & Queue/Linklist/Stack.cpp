#include <iostream>
using namespace std;

class Stack
{
	public: struct node
	{
		int data;
		node* nextAddress;
	};

	node* head;

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
	
};


int main(int argc, char const *argv[])
{
	Stack obj;

	return 0;
}