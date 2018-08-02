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

HashTable* Insert(HashTable* hashtable, HashTable* temp)
{
	if (hashtable == NULL)
	{
		hashtable = temp;

		return hashtable;
	}

	HashTable* travel;

	while(travel -> nextAddress != NULL)
	{
		travel = travel -> nextAddress;
	}

	travel -> nextAddress = temp;
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
	
	return 0;
}