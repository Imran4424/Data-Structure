#include <iostream>
using namespace std;

struct node {
    int data;
    node *left;
    node *right;
};

node* get_node(int info)
{
    node *temp = new node;
    temp->data = info;
    temp->left = temp->right = NULL;
    
    return temp;
}

node* binary_search_tree(node *root,int value)
{
    if(root == NULL){
        root = get_node(value);
    }
    else if(value<root->dint main()
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
}ata){
        root->left = binary_search_tree(root->left,value);
    }
    else if(value>=root->data){
        root->right = binary_search_tree(root->right,value);
    }
    
    return root;
}

void pre_order(node *root)
{
    if(tree){
        cout<<root->data<<" ";
        pre_order(root->left);
        pre_order(root->right);
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
