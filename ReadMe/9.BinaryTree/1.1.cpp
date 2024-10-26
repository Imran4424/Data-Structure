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

bool initialSubLeft = true;

Node* insert(Node* root, int value, bool isLeft) {
	// tree or subtree is NULL
	if (NULL == root) {
		root = new Node(value);
		return root;
	}

	// left child is NULL
	if (NULL == root -> left) {
		root -> left = insert(root -> left, value);
	} else if (NULL == root -> right) {
		// right child is NULL
		root -> right = insert(root -> right, value);
	} else {
		// both child is available
		
	}
}

int main(int argc, char const *argv[])
{
	Node* root = NULL;

	insert(root, 3, initialSubLeft);
	
	return 0;
}