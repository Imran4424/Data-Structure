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