#include <iostream>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};

node* get_node(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

node* insert_node(node* root,int info)
{
    if(root == NULL){
        root = get_node(info);
        return root;
    }
    else if(info < root->data){
        root->left = insert_node(root->left,info);
    }
    else if(info >= root->data){
        root->right = insert_node(root->right,info);
    }

    return root;
}

void deltree(node *root)
{
    if (root)
    {
        deltree(tree->left);
        deltree(tree->right);
        free(tree);
    }
}

int find_min(node *root)
{
    if(root == NULL){
        cout<<"Sorry,root is empty"<<endl;
        return -1
    }
    else if(root->left == NULL){
        return root->data;
    }

    return find_min(root->left);
}

int find_max(node *root)
{
    if(root == NULL){
        cout<<"Sorry,root is empty"<<endl;
        return -1
    }
    else if(root->right == NULL){
        return root->data;
    }

    return find_max(root->right);
}

void print_preorder(node* root)
{
    if(root){
        cout<<root->data<<" ";

        print_preorder(root->left);

        print_preorder(root->right);
    }
}

void print_inorder(node* root)
{
    if(root){

        print_inorder(root->left);

        cout<<root->data<<" ";

        print_inorder(root->right);
    }
}


void print_postorder(node* root)
{
    if(root){

        print_postorder(root->left);

        print_postorder(root->right);

        cout<<root->data<<" ";
    }
}


int main()
{
    node *root = new node;
    root = NULL;
    int val,i;

    for(i=1;i<=5;i++){
        cin>>val;

        root = insert_node(root,val);
    }

    print_preorder(root);

    return 0;
}

