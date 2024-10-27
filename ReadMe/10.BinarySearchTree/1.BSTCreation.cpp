/*
	1. Basic Binary Search Tree Creation:
	Problem: Write a program to create a binary search tree with the following 
	values: 50, 30, 20, 40, 70, 60, 80. 
	Display the structure of the tree.
*/

#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;

	Node() { }

	Node(int data) {
		this -> data = data;
		this -> left = NULL;
		this -> right = NULL;
	}
};

Node* insert(Node* root, int value) {
	// tree or subtree is NULL
	if (NULL == root) {
		root = new Node(value);
		return root;
	}

	// In case of not NULL following statements will run

	// left sub tree
	if (value < root -> data) {
		root -> left = insert(root -> left, value);
	} else {
		// right sub tree
		root -> right = insert(root -> right, value);
	}

	return root;
}

// pre order traversal
// root -> left -> right
void preOrder(Node* root) {
	if (NULL == root) {
		return;
	}

	cout << root -> data << " ";

	preOrder(root -> left);
	preOrder(root -> right);
}

// in order traversal
// left -> root -> right
void inOrder(Node* root) {
	if (NULL == root) {
		return;
	}

	inOrder(root -> left);

	cout << root -> data << " ";

	inOrder(root -> right);
}

// post order traversal
// left -> right -> root
void postOrder(Node* root) {
	if (root == NULL) {
		return;
	}

	postOrder(root -> left);
	postOrder(root -> right);

	cout << root -> data << " ";
}

int main(int argc, char const *argv[])
{
	// at first there is no node in the tree
	Node* root = NULL;

	int elementSize;
	cout << "how many elements you want to insert: ";
	cin >> elementSize;

	for (int i = 0; i < elementSize; ++i) {
		int input;
		cin >> input;
		root = insert(root, input);
	}

	return 0;
}