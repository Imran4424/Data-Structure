#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

int main()
{
    int info,i;
    node *start = new node;
    start = NULL;



    for(i=1;i<=5;i++){
        cin>>info;

        node *temp = new node;
        temp->data = info;
        temp->next = NULL;

        if(start == NULL){
            start = temp;
        }
        else{
            node *ptr;
            ptr = start;
            while(ptr->next != NULL){
                ptr = ptr->next;
            }
            ptr->next = temp;
        }
    }

    node *ptr;
    ptr = start;

    while(ptr!= NULL){
        cout<<ptr->data<<endl;
        ptr = ptr->next;
    }

    return 0;
}
