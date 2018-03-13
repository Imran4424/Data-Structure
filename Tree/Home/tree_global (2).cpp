#include <iostream>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};

node *root = new node;
node *ptr;

void insert_tree(int info)
{
    node *temp = new node;
    temp->data = info;
    temp->left = NULL;
    temp->right = NULL;


    if(root == NULL){
        root = temp;
    }
    else if(info <= ptr->data){
        ptr = ptr->left;
        insert_tree(info);
    }
    else if (info > ptr->data){
        ptr = ptr->right;
        insert_tree(info);
    }

}

void print_preorder()
{
    if(ptr){
        cout<<ptr->data<<endl;
        ptr = ptr->left;
        print_preorder();
        ptr = ptr->right;
        print_preorder();
    }
}


int main()
{
    root = NULL;
    ptr = root;
    int i, inf;

    for(i=1;i<=5;i++){
        cin>>inf;

        insert_tree(inf);
    }

    print_preorder();

    return 0;
}

