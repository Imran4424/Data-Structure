#include <stdio.h>

/*
	Trie Implementation in C
*/

typedef struct node {
    bool endMark;
    struct node *next[26];
} node;

void initTrieNode(node* current) {
	current -> endMark = false;
	for(int i = 0; i < 26; i++) {
		current -> next[i] = NULL;
	}
}

void trieInsertion(node* root,char *word) {
    node* travel = root;

    for(int i = 0; word[i]; i++) {
        int letter = word[i] - 'a';

        if(NULL == travel -> next[letter]) {
            travel -> next[letter] = malloc(sizeof(node));
            initTrieNode(travel -> next[letter]);
        }
        travel = travel -> next[letter];
    }
    /// marking the letters end point
    travel -> endMark = true;
}

bool searchTrie(node* root, char *word) {
	node* travel = root;

	for(int i = 0; word[i]; i++) {
		int letter = word[i] - 'a';

		if(NULL == travel -> next[letter]) {
			return false;
		}

		travel = travel -> next[letter];
	}

	return travel -> endMark;
}

void displayTrie(node* travel, char *word, int pos) {
	if(NULL == travel) {
		return;
	}

	if(travel -> endMark) {
		word[pos] = '\0';
		printf("%s\n", word);
	}

	for (int i = 0; i < 26; ++i)
	{
		if(travel -> next[i]) {
			word[pos] = i + 'a';
			displayTrie(travel -> next[i], word, pos + 1);
		}
	}
}

int main(int argc, char const *argv[])
{
	node* root = malloc(sizeof(node));
	initTrieNode(root);


	return 0;
}
