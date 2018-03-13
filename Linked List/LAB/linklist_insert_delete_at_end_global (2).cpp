#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

node *start = NULL;

void show();

void insert_at_end(int m)
{
    int info,i;

    for(i=1;i<=m;i++){
        cin>>info;

        node *temp = new node;
        temp->data=info;
        temp->next=NULL;
        if(start==NULL){
            start=temp;
        }
        else{
            node *temp1 = start;
            while(temp1->next != NULL){
                temp1 = temp1->next;
            }
            temp1->next = temp;
        }

    }
    show();
}

int delete_at_end(int m)
{
    int i;

    for(i=1;i<=m;i++){
        node *temp1 = start;

        if(temp1==NULL){
            cout<<endl<<"Sorry,List is empty"<<endl<<endl;
            return 0;
        }
        else if(temp1->next == NULL){
            temp1 = NULL;
            return 0;
        }
        else{
            while(temp1->next->next != NULL){
                temp1=temp1->next;
            }
            temp1->next=NULL;
        }

    }
    show();
    return 0;
}

void show()
{
    node *temp1 = start;
    cout<<endl;
    while(temp1!=NULL){
        cout<<temp1->data<<" ";
        temp1 = temp1->next;
    }
    cout<<endl<<endl;
}

void display()
{
    cout<<"Input 1 to insert node"<<endl;
    cout<<"Input 2 to delete node"<<endl;
    cout<<"Input 3 to terminate operation"<<endl;
}

int main()
{
    int indicate,n,i,j,info;

    while(1){
        display();
        cin>>indicate;
        if(indicate==1){
            cout<<"how many node you want to insert"<<endl;
            cin>>n;

            insert_at_end(n);

        }

        if(indicate==2){
            cout<<"how many node you want to delete"<<endl;
            cin>>n;

            delete_at_end(n);

        }

        if(indicate==3){
            break;
        }

    }

    return 0;
}
