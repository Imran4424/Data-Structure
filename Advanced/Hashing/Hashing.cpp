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

	HashTable() { }
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

	cout << "enter the informations" << endl;

	for (int i = 0; i < 2; ++i)
	{
		int number;
		string name;

		cin >> number >> name;

		int temp_key = HashCode(number,size);

		HashTable *temp = new HashTable();

		temp -> key = temp_key;
		temp -> number = number;
		temp -> name = name;
		temp -> nextAddress = NULL;

	
		hashtable[temp_key] = Insert(hashtable[temp_key],temp);
	}

	cout<<"Input the target number what you want to find about"<<endl;

	int target;
	cin>>target;

	Search(hashtable[HashCode(target,size)], target);
	
	cout<<"Input the target number what you want to find about"<<endl;
	cin>>target;
	Search(hashtable[HashCode(target,size)], target);
	
	return 0;
}