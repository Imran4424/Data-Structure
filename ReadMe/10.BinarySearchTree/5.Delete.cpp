/*
	5. Delete a Node from a Binary Search Tree:
	Problem: Write a function to delete a node from a binary search tree. Use the tree from 
	the previous problem and delete the node with the value 70
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

Node* insertNode(Node* root, int value) {
	// tree or subtree is NULL
	if (NULL == root) {
		root = new Node(value);
		return root;
	}

	// In case of not NULL following statements will run

	// left sub tree
	if (value < root -> data) {
		root -> left = insertNode(root -> left, value);
	} else {
		// right sub tree
		root -> right = insertNode(root -> right, value);
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

Node* deleteNode(Node* root, int target) {
	// base condition
	if (NULL == root) {
		return root;
	}

	if (target < root -> data) {
		root -> left = deleteNode(root -> left, target);
	} else if (target > root -> data) {
		root -> right = deleteNode(root -> right, target);
	} else {
		// target == root -> data
		// when we are deleting there can be four cases
		
		// case one - leaf node
		if (NULL == root -> left && NULL == root -> right) {
			root = NULL;
		} else if (NULL == root -> left) {
			// case two - only right node exist
			root = root -> right;
		} else if (NULL == root -> right) {
			// case three - only left node exist
			root = root -> left;
		} else {
			// case four - both left and right node exist

			// replace value is a choice
			// if we want to get the from left sub tree then we need to get max of left sub tree
			// if we want to get the from right sub tree then we need to get min of right sub tree
			int replaceValue = findMinValue(root -> right);

			// replace the data of root with replaceValue
			root -> data = replaceValue;

			// since there is two copies of replaceValue now
			// we need to delete the replaceValue from right sub tree recursively
			root -> right = deleteNode(root -> right, replaceValue);
		}
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
	cout << "how many elements you want to insertNode: ";
	cin >> elementSize;

	for (int i = 0; i < elementSize; ++i) {
		int input;
		cin >> input;
		root = insertNode(root, input);
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