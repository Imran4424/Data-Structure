/*
	3.Understanding Collisions
	Write a program to implement basic hashing using the hash function 
	( h(k) = k \mod 5 ), insert the keys 5, 10, 15 into an array of size 5. 
	Observe what happens when multiple keys hash to the same index and explain 
	the concept of collisions.
*/

#include <iostream>
using namespace std;

int hashArray[5];

int hashing(int value) {
	return value % 5;
}

int main(int argc, char const *argv[])
{
	// init the hash array
	for (int i = 0; i < 5; ++i) {
		hashArray[i] = -1;
	}

	// every time the above hash functions is returning 0
	// that why it's creating collision
	hashArray[hashing(5)] = 5;
	hashArray[hashing(10)] = 10;

	// in case of collision previous value will be erased
	// only latest one will remain
	// because we are assigning values to the same index
	hashArray[hashing(15)] = 15;

	cout << "Displaying the hash array" << endl;
	for (int i = 0; i < 5; ++i) {
		cout << hashArray[i] << " ";
	}
	
	cout << endl;

	return 0;
}

/*
	what is hash function?

	Hash function is basically the mapping procedure of values to Hash data structure.
	
	This process known as hashing. and it is usually done by using hash functions.

	In our previous code we mapped 
	a to 0
	b to 1
	c to 3
	......
	......
	......
	z to 25

	using hashing
*/