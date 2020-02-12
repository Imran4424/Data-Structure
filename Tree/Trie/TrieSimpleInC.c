
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

int main(int argc, char const *argv[])
{
	node* root = malloc(sizeof(node));

	return 0;
}
