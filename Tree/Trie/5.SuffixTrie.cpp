#include <iostream>
#include <string>
using namespace std;

struct Node
{
	bool endMark;
	Node* next[26];

	Node() {
		endMark = false;
		for (int i = 0; i < 26; i++) {
			next[i] = NULL;
		}
	}
};

class Trie
{
	Node* root;

	void insertionHelper(string word) {
		Node *travel = root;

		for (int i = 0; word[i]; i++) {
			int letter = word[i] - 'a';

			if (NULL == travel->next[letter]) {
				travel->next[letter] = new Node();
			}

			travel = travel->next[letter];
		}

		travel->endMark = true;
	}
public:
	Trie() {
		root = new Node();
	}

	void reset() {
		root = new Node();
	}

	void insert(string word) {
		for (int i = 0; word[i]; i++) {
			insertionHelper(word.substr(i));
		}
	}

	bool search(string word) {
		Node *travel = root;

		for (int i = 0; word[i]; i++) {
			int letter = word[i] - 'a';

			if (NULL == travel->next[letter]) {
				return false;
			}

			travel = travel->next[letter];
		}

		return travel->endMark;
	}
};

int main(int argc, char const *argv[])
{
	Trie myTrie;
	return 0;
}