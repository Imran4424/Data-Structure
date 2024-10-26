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
	Node* root = NULL;

	root = new Node(3);
	root -> left = new Node(7);
	root -> right = new Node(6);


	root -> left -> left = new Node(9);
	root -> left -> right = new Node(7);

	root -> right -> left = new Node(12);
	root -> right -> right = new Node(8);

	cout << "preOrder" << endl;
	preOrder(root);
	cout << endl;
	
	cout << "inOrder" << endl;
	inOrder(root);
	cout << endl;

	cout << "postOrder" << endl;
	postOrder(root);
	cout << endl;

	return 0;
}