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
        if(start == NULL){
            start =temp;
        }
        else{
            node temp1 =start;
            while(temp1->next != NULL){
                temp1=temp1->next;
            }
            temp1->next=start;
        }
    }
    show();
}

void insert_at_start(int m)
{
    int info,i;

    for(i=1;i<=m;i++){
        cin>>info;
        node *temp = new node;
        temp->data = info;
        if(start == NULL){
            start = temp;
            temp->next = NULL;
        }
        else{
            temp->next = start;
            start->=temp;
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

int delete_at_start(int m){
    int i;

    for(i=1;i<=m;i++){

        if(start==NULL){
            cout<<endl<<"Sorry,List is empty"<<endl<<endl;
            return 0;
        }

        else{
            start=start->next;
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
        temp1=temp1->next;
    }
    cout<<endl<<endl;
}

int main()
{


}
