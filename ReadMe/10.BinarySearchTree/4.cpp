/*
	3. Find the Minimum and Maximum in a Binary Search Tree:
	Problem: Write functions to find the minimum and maximum values in a binary search tree. 
	Use the BST from the previous problems to find both.
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

bool search(Node* root, int target) {
	// tree or subtree is NULL
	if (NULL == root) {
		return false;
	}

	if (target == root -> data) {
		return true;
	}

	// left sub tree
	if (target < root -> data) {
		return search(root -> left, target);
	} else {
		// right sub tree
		return search(root -> right, target);
	}

}

int findMinValue(Node *root) {
	// this is a safety check
	// in real scenario
	// this condition will not check
	if (NULL == root) {
		// Indication of error
		return -404;
	}

	// base condition
	if (NULL == root -> left) {
		return root -> data;
	}

	return findMinValue(root -> left);
}

int findMaxValue(Node *root) {
	// this is a safety check
	// in real scenario
	// this condition will not check
	if (NULL == root) {
		// Indication of error
		return -404;
	}

	// base condition
	if (NULL == root -> right) {
		return root -> data;
	}

	return findMaxValue(root -> right);
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

	int target;
	cout << "enter a target value to search: ";
	cin >> target;

	if(search(root, target)) {
		cout << target << " does exist in the BST" << endl;
	} else {
		cout << target << " does not exist in the BST" << endl;
	}

	return 0;
}