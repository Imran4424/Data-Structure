#include <iostream>
#include <string>
using namespace std;

int HashCode(int number, int size)
{
	return number % size;
}

struct HashTable
{
	int data

	HashTable *nextAddress;

	HashTable() { }

	HashTable(int value)
	{
		data = value;
		nextAddress = NULL;
	}
};

void Insert(HashTable* head, HashTable* temp)
{
	if (NULL == head)
	{
		head = temp;

		return;
	}

	HashTable* travel = head;

	while(travel -> nextAddress != NULL)
	{
		travel = travel -> nextAddress;
	}

	travel -> nextAddress = temp;
}

void Search(HashTable* travel,int target)
{
	while(NULL != travel)
	{
		if (travel -> data == target)
		{
			cout << "target is found"<<endl;

			cout << "Value is: " << travel -> data <<endl;

			return;
		}

		travel = travel -> nextAddress;
	}

	cout<<"target is not found"<<endl;
}