#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

int main()
{
    node *start = new node;
    start = NULL;

    int n;

    while(cin>>n){
        if(n<0){
            break;
        }
        node *temp = new node;

        temp->data= n;
        temp->next=NULL;

        if(start == NULL){
            start = temp;
        }
        else{
            node *temp1;
            temp1 = start;

            while(temp1->next != NULL){
                temp1 = temp1->next;
            }
            temp1->next=temp;
        }
    }

    node *temp1 = start;

    while(temp1 != NULL){
        cout<<temp1->data<<endl;
        temp1=temp1->next;
    }

    return 0;
}
