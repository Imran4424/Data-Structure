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

void just_delete(node **root,int val)
{
    if((*root)->left == NULL && (*root)->right == NULL){
        (*root) = NULL;
    }
    else if((*root)->left != NULL && (*root)->right == NULL){
        *root = (*root)->left;
    }
    else if((*root)->right != NULL && (*root)->left == NULL){
        (*root) = (*root)->right;
    }
    
    else{
        node *temp = (*root)->right;
        (*root) = (*root)->left;
        node *ptr = (*root);
        while(ptr->right != NULL){
            ptr = ptr->right;
        }
        ptr->right = temp;
    }
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

}

void del_node(node **root,int val)
{
    if(*root == NULL){
        cout<<"node not found"<<endl;
    }
    else if((*root)->data == val){
        just_delete(&(*root),val);
    }
    else if((*root)->data > val){
        del_node(&(*root)->left,val);
    }
    else if((*root)->data <= val){
        del_node(&(*root)->right,val);
    }

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
    int val,i,n;
    
    cout<<"input your desired node"<<endl;
    cin>>n;

    for(i=1;i<=n;i++){
        cin>>val;

        root = insert_node(root,val);
    }

    print_preorder(root);
    cout<<endl;
    print_inorder(root);
    cout<<endl;
    print_postorder(root);
    cout<<endl;

    return 0;
}
