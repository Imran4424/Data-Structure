/*
	3. Search for a Node in a Binary Search Tree:
	Problem: Write a function to search for a node with a specific value in a binary search tree. 
	Use the tree created in the first problem to search for the value 40
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
	if (value < root -> data) {
		return search(root -> left, target);
	} else {
		// right sub tree
		return search(root -> right, target);
	}

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