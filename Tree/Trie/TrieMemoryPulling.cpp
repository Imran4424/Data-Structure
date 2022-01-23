#include <iostream>
#include <string>
using namespace std;

struct Node
{
	int count;
	Node *next[26];

	Node() {
		count = 0;
		for (int i = 0; i < 26; i++) {
			next[i] = NULL;
		}
	}
};

Node myNode[600000];
int nodeIndex;

class Trie {
	Node* root;
	string givenWord;
	int wCount;

	void deleteAll(Node* travel) {
		for (int i = 0 ; i < 26; i++) {
			if (NULL != travel -> next[i]) {
				deleteAll(travel -> next[i]);
			}
		}

		delete travel;
	}

	void searchAll(Node* travel, int index) {
		// base case
		if (index == givenWord.size()) {
			if (travel->count > 0) {
				wCount += travel->count;
			}

			return;
		}

		// here ? is the wild char
		if ('?' == givenWord[index]) {
			for (int i = 0; i < 26; i++) {
				if (NULL != travel->next[i]) {
					searchAll(travel->next[i], index + 1);
				}
			}
		} else {
			int letter = givenWord[index] - 'a';

			searchAll(travel->next[letter], index + 1);
		}
	}

	void removeAll(Node* travel, int index) {
		// base case
		if (index == givenWord.size()) {
			if (travel->count > 0) {
				wCount += travel->count;
				travel->count = 0;
			}

			return;
		}

		// here ? is the wild char
		if ('?' == givenWord[index]) {
			for (int i = 0; i < 26; i++) {
				if (NULL != travel->next[i]) {
					removeAll(travel->next[i], index + 1);
				}
			}
		} else {
			int letter = givenWord[index] - 'a';

			removeAll(travel->next[letter], index + 1);
		}
	}

	void displayTrie(Node *travel, string word) {
		if (travel->count > 0) {
			cout << word << endl;
		}

		for (int i = 0; i < 26; i++) {
			if (NULL != travel -> next[i]) {
				displayTrie(travel -> next[i], word + string(1, i + 'a'));
			}
		}
	}

public:
	Trie() {
		root = new Node();
	}

	void reset() {
		root = new Node();
	}

	int insert(string word) {
		Node* travel = root;

		for (int i = 0; word[i]; i++) {
			int letter = word[i] - 'a';

			if (NULL == travel -> next[letter]) {
				travel -> next[letter] = &myNode[nodeIndex++];
			}

			travel = travel -> next[letter];
		}

		travel->count++;

		return travel->count;
	}

	int search(string word) {
		wCount = 0;
		givenWord = word;
		searchAll(root, 0);

		return wCount;
	}

	int remove(string word) {
		wCount = 0;
		givenWord = word;
		removeAll(root, 0);

		return wCount;
	}

	void clear() {
		deleteAll(root);
	}

	void printAllString() {
		displayTrie(root, "");
	}
};


// length wise trie
Trie myTrie[31];

void init() {
	nodeIndex = 0;

	for (int i = 1; i < 31; i++) {
		myTrie[i].reset();
	}
}

int addWord(string word) {
	return myTrie[word.size()].insert(word);
}

int searchWord(string word) {
	// return how many same words are searched
	return myTrie[word.size()].search(word);
}

int removeWord(string word) {
	// return how many same words are deleted
	return myTrie[word.size()].remove(word);
}

int main(int argc, char const *argv[])
{
	
	return 0;
}
