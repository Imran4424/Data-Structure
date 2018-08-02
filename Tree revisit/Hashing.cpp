#include <iostream>
#include <string>
using namespace std;

int HashCode(int number, int size)
{
	return number % 20;
}

struct HashTable
{
	int key;
	int number;
	string name;

	HashTable *nextAddress;
};

HashTable* Insert(HashTable* head, HashTable* temp)
{
	if (head == NULL)
	{
		head = temp;

		return head;
	}

	HashTable* travel;

	while(travel -> nextAddress != NULL)
	{
		travel = travel -> nextAddress;
	}

	travel -> nextAddress = temp;
}

void Search(HashTable* travel,int target)
{
	while(travel != NULL)
	{
		if (travel -> number == target)
		{
			cout<<"target is found"<<endl;

			cout<<"key: "<<travel -> key<<endl;
			cout<<"number: "<< travel -> number<<endl;
			cout<<"name: "<< travel -> name<<endl;

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
	cin>>size;

	HashTable *hashtable[size];

	for (int i = 0; i < size; ++i)
	{
		hashtable[i] = NULL;
	}

	cout<<"enter the informations"<<endl;

	for (int i = 0; i < size; ++i)
	{
		int number;
		string name;

		cin>>number>>name;

		HashTable *temp;

		temp -> key = HashCode(number,size);
		temp -> number = number;
		temp -> name = name;
		temp -> nextAddress = NULL;

		hashtable[HashCode(number,size)] = Insert(hashtable[HashCode(number,size)],temp);
	}

	cout<<"Input the target number what you want to find about"<<endl;

	int target;
	cin>>target;

	Search(hashtable[HashCode(target,size)],)
	
	return 0;
}