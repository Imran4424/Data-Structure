#include <iostream>
#include <string>
using namespace std;

int HashCode(int number, int size)
{
	return number % size;
}

struct HashTable
{
	int data;

	HashTable *nextAddress;

	HashTable() { }

	HashTable(int value)
	{
		data = value;
		nextAddress = NULL;
	}
};

HashTable* Insert(HashTable* head, HashTable* temp)
{
	if (NULL == head)
	{
		head = temp;

		return head;
	}

	HashTable* travel = head;

	while(travel -> nextAddress != NULL)
	{
		travel = travel -> nextAddress;
	}

	travel -> nextAddress = temp;

	return head;
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

int main(int argc, char const *argv[])
{
	cout<<"Enter the size of the table"<<endl;

	int size;
	cin >> size;

	HashTable *hashtable[size];

	// initialize
	for (int i = 0; i < size; ++i)
	{
		hashtable[i] = NULL;
	}

	cout << "enter the informations" << endl;

	for (int i = 0; i < 3; ++i)
	{
		int value;

		cin >> value;

		int temp_key = HashCode(value, size);

		HashTable *temp = new HashTable(value);

		hashtable[temp_key] = Insert(hashtable[temp_key], temp);
	}

	cout << "Input the target number what you want to find about" << endl;

	int target;
	cin >> target;

	Search(hashtable[HashCode(target,size)], target);
	
	cout << "Input the target number what you want to find about"<<endl;
	
	cin >> target;

	Search(hashtable[HashCode(target,size)], target);
	
	return 0;
}