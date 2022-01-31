#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

struct Node
{
	int count;
	unordered_map<char, Node*> child;

	Node () {
		count = 0;
	}
};

Node myNode[600000];
int nodeIndex;

class Trie
{
	Node* root;
	string givenWord;
	int wCount;

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
			for (auto itr : travel->child) {
				searchAll(travel->child[itr.first], index + 1);
				// alternative call
				// searchAll(itr.second, index + 1);
			}
		} else {
			if (travel->child.count(givenWord[index])) {
				searchAll(travel->child[givenWord[index]], index + 1);
			}
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
			for (auto itr : travel->child) {
				removeAll(travel->child[itr.first], index + 1);
				// alternative call
				// removeAll(itr.second, index + 1);
			}
		} else {
			if (travel->child.count(givenWord[index])) {
				removeAll(travel->child[givenWord[index]], index + 1);
			}
		}
	}

	void displayTrie(Node *travel, string word) {
		if (travel->count > 0) {
			cout << word << endl;
		}

		for (auto itr : travel->child) {
			displayTrie(travel->child[itr.first], word + string(1, itr.first));
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
			if (!travel->child.count(word[i])) {
				travel->child[word[i]] = &myNode[nodeIndex++];
			}

			travel = travel->child[word[i]];
		}

		travel->count++;

		return travel->count;
	}

	int search(string word) {
		Node* travel = root;

		for (int i = 0; word[i]; i++) {
			if (!travel->child.count(word[i])) {
				return false;
			}

			travel = travel->child[word[i]];
		}

		return travel->count;
	}

	int searchWild(string word) {
		wCount = 0;
		givenWord = word;
		searchAll(root, 0);

		return wCount;
	}

	int removeWild(string word) {
		wCount = 0;
		givenWord = word;
		removeAll(root, 0);

		return wCount;
	}

	bool startsWith(string prefix) {
		Node* travel = root;

		for (int i = 0; prefix[i]; i++) {
			if (!travel->child.count(prefix[i])) {
				return false;
			}

			travel = travel->child[prefix[i]];
		}

		return true;
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
	return myTrie[word.size()].searchWild(word);
}

int removeWord(string word) {
	// return how many same words are deleted
	return myTrie[word.size()].removeWild(word);
}

int main(int argc, char const *argv[])
{
	
	return 0;
}