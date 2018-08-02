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
};


int main(int argc, char const *argv[])
{
	cout<<"Enter the size of the table"<<endl;

	int size;
	cin>>size;

	HashTable hashtable[size];

	cout<<"enter the informations"<<endl;

	for (int i = 0; i < count; ++i)
	{
		/* code */
	}
	
	return 0;
}