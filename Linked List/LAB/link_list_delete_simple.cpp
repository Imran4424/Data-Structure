#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};


int main()
{
    node *start;
    start=NULL;
    int n;

    while(1){
        cin>>n;
        if(n<0){
            break;
        }

        node *temp;
        temp = new node;
        temp->data=n;
        temp->next=NULL;

        if(start == NULL){
            start = temp;
        }
        else{
            node *temp1;
            temp1 = start;

            while(temp1->next!=NULL){
                temp1=temp1->next;
            }
            temp1->next= temp;
        }
    }
    node *temp1 = start;

    while(temp1!=NULL){
        cout<<temp1->data<<" ";
        temp1=temp1->next;
    }
    cout<<endl;

    temp1 = start;

    if(temp1==NULL){
        cout<<"LIST is empty"<<endl;
    }
    else if(temp1->next==NULL){
        temp1 = NULL;
    }
    else{
        while(temp1->next->next!=NULL){
            temp1 = temp1->next;
        }
        temp1->next=NULL;
    }

    temp1 =start;

    while(temp1!=NULL){
        cout<<temp1->data<<" ";
        temp1 = temp1->next;
    }
    cout<<endl;

    return 0;
}
