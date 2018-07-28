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
	
};


int main(int argc, char const *argv[])
{
	Stack obj;

	return 0;
}