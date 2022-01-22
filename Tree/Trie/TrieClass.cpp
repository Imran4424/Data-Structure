#include <iostream>
#include <string>
using namespace std;

class Trie {
	struct Node
	{
		bool endMark;
		Node *next[26];

		Node() {
			endMark = false;
			for (int i = 0; i < 26; i++) {
				next[i] = NULL;
			}
		}
	};

	Node* root;

	void deleteAll(Node* travel) {
		for (int i = 0 ; i < 26; i++) {
			if (NULL != travel -> next[i]) {
				deleteAll(travel -> next[i]);
			}
		}

		delete travel;
	}

	void displayTrie(Node *travel, string word) {
		if (travel->endMark) {
			cout << word << endl;
		}

		for (int i = 0; i < 26; i++) {
			if (NULL != travel -> next[i]) {
				// for storing
				string medium = word;
				medium.push_back('a' + i);
				displayTrie(travel -> next[i], medium);
			}
		}
	}

	string toLower(string word) {
		for (int i = 0 ; word[i]; i++) {
			if (word[i] >= 'A' && word[i] <= 'Z') {
				word[i] += 32;
			}
		}

		return word;
	}

public:
	Trie() {
		root = new Node();
	}

	void reset() {
		root = new Node();
	}

	void insert(string word) {
		Node* travel = root;

		word = toLower(word);

		for (int i = 0; word[i]; i++) {
			int letter = word[i] - 'a';

			if (NULL == travel -> next[letter]) {
				travel -> next[letter] = new Node();
			}

			travel = travel -> next[letter];
		}

		travel -> endMark = true;
	}

	bool search(string word) {
		Node* travel = root;

		word = toLower(word);

		for (int i = 0; word[i]; i++) {
			int letter = word[i] - 'a';

			if (NULL == travel -> next[letter]) {
				return false;
			}

			travel = travel -> next[letter];
		}

		return travel -> endMark;
	}

	

	void deleteTree() {
		deleteAll(root);
	}

	void printAllString() {
		displayTrie(root, "");
	}
};

int main(int argc, char const *argv[])
{
	Trie myTrie;

	myTrie.insert("Imran");
	myTrie.insert("Sakib");
	myTrie.insert("Shoudha");
	myTrie.insert("Shaira");
	myTrie.insert("Sujan");
	myTrie.insert("Dictionary");

	myTrie.printAllString();

	cout << "Is Dictionary in the Trie: " << myTrie.search("Dictionary") << endl;
	cout << "Is Book in the Trie: " << myTrie.search("Book") << endl;
	
	return 0;
}
