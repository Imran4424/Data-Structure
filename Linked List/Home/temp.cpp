#include <iostream>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};

node *root = NULL;

int insert(int m)
{
    if(root==NULL){
        root->data =m;
        root->left=NULL;
        root->right=NULL;
    }
    else{
        node *temp = new node;
        temp->data = m;
        temp->left = NULL;
        temp->right = NULL;

        node *pot = root;

        if(pot->data>m){
            while(pot->left!=NULL){
                pot = pot->left;
                if(pot->data <= m){
                    while(pot->)
                }

            }
            pot->left = temp;
        }

    }
}

    show();
}
