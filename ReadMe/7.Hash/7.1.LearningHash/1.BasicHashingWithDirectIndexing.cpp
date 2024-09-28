/*
	1.Basic Hashing with Direct Indexing:
	Write a program to check if two strings are anagrams of each other.
	Two strings are called anagrams if they use the same characters in the same frequency, 
	but in any order. For example, "listen" and "silent" are anagrams.

	Use an array to count the frequency of each character in both strings to determine 
	if they are anagrams.
*/

#include <iostream>
using namespace std;

bool isAnagram(string source, string target) {

}

int main(int argc, char const *argv[])
{
	
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
	But we can also 

*/