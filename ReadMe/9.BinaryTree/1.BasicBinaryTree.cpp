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
	
	return 0;
}