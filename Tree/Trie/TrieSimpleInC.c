
/*
	Trie Implementation in C
*/

typedef struct node {
    bool endMark;
    struct node *next[26];
    int length;
} node;