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

	
};