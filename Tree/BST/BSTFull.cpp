/// BST full

#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left, *right;

    node() {}

    node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

node* InsertNode(node* root, int value)
{
    if(NULL == root)
    {
        root = new node(value);
    }
    else if(value < root -> data)
    {
        root -> left = InsertNode(root -> left, value);
    }
    else if(value > root -> data)
    {

        root -> right = InsertNode(root -> right, value);
    }

    return root;
}

int MinValue(node* root)
{
    if(NULL == root -> left)
    {
        return root -> data;
    }

    return MinValue(root -> left);
}

int MaxValue(node* root)
{
    if(NULL == root -> right)
    {
        return root -> data;
    }

    return MaxValue(root -> right);
}

node* DeleteNode(node* root, int target)
{
    if(NULL == root)
    {
        return root;
    }

    if(target > root -> data)
    {
        root -> right = DeleteNode(root -> right, target);
    }
    else if(target < root -> data)
    {
        root -> left = DeleteNode(root -> left, target);
    }
    else
    {
        if(NULL == root -> left && NULL == root -> right)
        {
            root = NULL;
        }
        else if(NULL == root -> left)
        {
            root = root -> right;
        }
        else if(NULL == root -> right)
        {
            root = root -> left;
        }
        else
        {
            int replaceNode = MinValue(root -> right);

            root -> data = replaceNode;

            root -> right = DeleteNode(root -> right, replaceNode);
        }
    }

    return root;
}

void Mirror(node* root)
{
    if(NULL == root)
    {
        return;
    }

    // swapping nodes
    node* temp = root -> left;
    root -> left = root -> right;
    root -> right = temp;

    Mirror(root -> left);
    Mirror(root -> right);
}

void PreOrder(node* root)
{
    if(NULL == root)
    {
        return;
    }

    cout << root -> data << endl;
    PreOrder(root -> left);
    PreOrder(root -> right);
}

void InOrder(node* root)
{
    if(NULL == root)
    {
        return;
    }

    InOrder(root -> left);
    cout << root -> data << endl;
    InOrder(root -> right);
}

void PostOrder(node* root)
{
        if(NULL == root)
        {
            return;
        }

        PostOrder(root -> left);
        PostOrder(root -> right);
        cout << root -> data << endl;
}

void Ascending(node* root)
{
    if(NULL == root)
    {
        return;
    }

    Ascending(root -> left);
    cout << root -> data << endl;
    Ascending(root -> right);
}

void Descending(node* root)
{
    if(NULL == root)
    {
        return;
    }

    Descending(root -> right);
    cout << root -> data << endl;
    Descending(root -> left);
}


int main()
{
    node* root = NULL;

    cout << "How many nodes you wanna insert?" << endl;
	int num;
	cin >> num;

	cout << "enter the values" << endl;

	int inputValue;

	for (int i = 0; i < num; ++i)
	{
		cin >> inputValue;

		root = InsertNode(root, inputValue);

	}

	cout << "Pre Order Traversal: " << endl;
	PreOrder(root);
	cout << endl << endl;

	cout << "In Order Traversal: " << endl;
	InOrder(root);
	cout << endl << endl;

	cout << "Post Order Traversal: " << endl;
	PostOrder(root);
	cout << endl << endl;

	cout << "Ascending: " << endl;
	Ascending(root);
	cout << endl << endl;

	cout << "Descending: " << endl;
	Descending(root);
	cout << endl << endl;

	cout << "How many nodes you want to delete" << endl;

	int delNum;
	cin >> delNum;

	cout << "enter the number you want to delete" << endl;

	int target;

	for (int i = 0; i < delNum; ++i)
	{
		cin >> target;

		root = DeleteNode(root, target);
	}

	cout << "Pre Order Traversal: " << endl;
	PreOrder(root);
	cout << endl << endl;

	cout << "In Order Traversal: " << endl;
	InOrder(root);
	cout << endl << endl;

	cout << "Post Order Traversal: " << endl;
	PostOrder(root);
	cout << endl << endl;

	cout << "Ascending: " << endl;
	Ascending(root);
	cout << endl << endl;

	cout << "Descending: " << endl;
	Descending(root);
	cout << endl << endl;

    return 0;
}
