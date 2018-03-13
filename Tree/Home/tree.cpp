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

void insert_node(node **root,int info)
{
    if(*root == NULL){
        *root = get_node(info);
    }
    else if(info <= (*root)->data){
        insert_node(&(*root)->left,info);
    }
    else if(info > (*root)->data){
        insert_node(&(*root)->right,info);
    }

}

void print_preorder(node* root)
{
    if(root){
        cout<<root->data<<" ";

        print_preorder(root->left);

        print_preorder(root->right);
    }
    cout<<endl;
}

void print_inorder(node* root)
{
    if(root){

        print_inorder(root->left);

        cout<<root->data<<" ";

        print_inorder(root->right);
    }
    cout<<endl;
}


void print_postorder(node* root)
{
    if(root){

        print_postorder(root->left);

        print_postorder(root->right);

        cout<<root->data<<" ";
    }
    cout<<endl;
}


int main()
{
    node *root = new node;
    root = NULL;
    int val,i;

    for(i=1;i<=5;i++){
        cin>>val;

        insert_node(&root,val);
    }

    print_preorder(root);

    return 0;
}

