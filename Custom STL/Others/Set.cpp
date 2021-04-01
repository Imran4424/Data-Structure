#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<malloc.h>

typedef struct Node {
	int key;
	Node *left, *right;
};

Node *newNode(int item) {
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

Node *current;

Node *addRec(Node *node, int key) {
	if (node == NULL)
		return newNode(key);

	if (key < node->key)
		node->left = addRec(node->left, key);
	else if (key > node->key)
		node->right = addRec(node->right, key);

	return node;
}

void add(int key) {
	current = addRec(current, key);
}

bool findRec(Node *node, int key) {
	if (node != NULL) {
		if (key == node->key)
			return true;
		if (findRec(node->left, key))
			return true;
		if (findRec(node->right, key))
			return true;
	}

	return false;
}

bool contains(int key) {
	return findRec(current, key);
}

void printAll(Node *node) {
	if (node != NULL) {
		printAll(node->left);
		printf("%d ", node->key);
		printAll(node->right);
	}
}

void printAll() {
	printAll(current);
}

Node *minValueNode(Node *node) {
	Node *current = node;

	while (current->left != NULL)
		current = current->left;

	return current;
}

Node *removeRec(Node *node, int key) {
	if (node == NULL)
		return node;

	if (key < node->key)
		node->left = removeRec(node->left, key);
	else if (key > node->key)
		node->right = removeRec(node->right, key);
	else {
		if (node->left == NULL) {
			Node *temp = node->right;
			free(node);
			return temp;
		}
		else if (node->right == NULL) {
			Node *temp = node->left;
			free(node);
			return temp;
		}

		Node* temp = minValueNode(node->right);
		node->key = temp->key;
		node->right = removeRec(node->right, temp->key);
	}

	return node;
}

void remove(int key) {
	current = removeRec(current, key);
}

int main(void) {
	
	int T, N;

	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; ++test_case) {

		current = NULL;

		scanf("%d", &N);

		for (int i = 0; i < N; ++i) {

			int cmd, key;

			scanf("%d%d", &cmd, &key);

			switch (cmd) {
			case 1:
				add(key);
				break;
			case 2:
				remove(key);
				break;
			}
		}

		printf("#%d ", test_case);
		printAll();
		printf("\n");
	}
}

//// set