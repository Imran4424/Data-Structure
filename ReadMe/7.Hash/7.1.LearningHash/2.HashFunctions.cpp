/*
	2.Hash Functions:
	Write a program to check if two strings are anagrams of each other.
	Two strings are called anagrams if they use the same characters in the same frequency, 
	but in any order. For example, "listen" and "silent" are anagrams.

	Use an array to count the frequency of each character in both strings to determine 
	if they are anagrams.

	Use hash functions.
*/

#include <iostream>
using namespace std;

int sCount[26];
int tCount[26];

/*
	hash functions is nothing but using a technique to mapped values.

	and hasCode is the processed index or key hash functions will return
	
	The best hash function will always produce unique hash code
*/
int hashing(char ch) {
	// type casting
	int hashCode = int(ch - 'a');

	return hashCode;
}

bool isAnagram(string source, string target) {
	// first init both frequency count array
	for (int i = 0; i < 26; ++i) {
		sCount[i] = 0;
		tCount[i] = 0;
	}

	// counting frequency of source
	for (int i = 0; i < source.size(); ++i) {
		sCount[hashing(source[i])] += 1;
	}

	// couting the frequecy of target
	for (int i = 0; i < target.size(); ++i) {
		tCount[hashing(target[i])]++;
	}

	// let's compare
	// if they anagram or not
	for (int i = 0; i < 26; ++i) {
		if (sCount[i] != tCount[i]) {
			return false;
		}
	}

	return true;
}

int main(int argc, char const *argv[])
{
	string source = "pritha";
	string target = "ahtirp";

	if (isAnagram(source, target)) {
		cout << "Both are anagram" << endl;
	} else {
		cout << "They are not anagram of each other" << endl;
	}

	return 0;
}

/*
	For learning this hash implementation

	we gonna solve a problem called Valid Anagram from leetcode

	Now question is, What is anagram?
	Anagram is rearragnement of letters of a string.

	for example:

	given string: pritha

	anagrams are:
		irptha
		ahtirp
*/

/*
	Now, let's solve it
	For that we need to calculate frequency of character for both soruce and destination
	strings

	For calculation we are gonna use a Dictionary first. Dictionary is another data structure
	but don't go there. I am just trying to teach you the concept.

	let's say dictionary name is dict

	for pritha 
	
	dict[a] = 1

	here, a is key, and 1 is the value

	similary the full dictionary of whole alphabet
	dict[a] = 1
	dict[b] = 0
	dict[c] = 0
	dict[d] = 0
	dict[e] = 0
	dict[f] = 0
	dict[g] = 0
	dict[h] = 1
	dict[i] = 1
	dict[j] = 0
	dict[k] = 0
	dict[l] = 0
	dict[m] = 0
	dict[n] = 0
	dict[o] = 0
	dict[p] = 1
	dict[q] = 0
	dict[r] = 1
	dict[s] = 0
	dict[t] = 1
	dict[u] = 0
	dict[v] = 0
	dict[w] = 0
	dict[x] = 0
	dict[y] = 0
	dict[z] = 0
*/

/*
	We can also solve this using hash, hash is a datastructure also works on key value pair.

	But we are gonna used a array based hash which is the most basic hash.

	for that we need to map a - z to array indexes
	we can map 
	a to 0
	b to 1
	c to 3
	......
	......
	......
	z to 25

	this mapping is reconized as hashing technique

	hash introduced to solve the shortcoming of array and use the benefits of array
*/