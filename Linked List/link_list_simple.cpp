#include <iostream>
using namespace std;

struct node{
    int info;
    node *link;
};
//typedef struct node *nodeptr;

node* provide()
{
    node *q = new node;

    return q;
}

node* insertnode (node *ptr, int val){
	node *q;
	q = provide();
	
	q->info = val;
	ptr -> link = q;
	return q;
}

int main()
{
    node *start,*ptr;

    int indicator,val,count;
    
    start = provide();
    ptr = start;
    ptr->info= 55;
	
	cout<<"Enter a negative value to terminate"<<endl;
	
    while(cin>>val){
        if(val<0){
            break;
        }
        
        ptr = insertnode(ptr,val);
    }
    ptr = start;

    while(ptr!=0){
		cout<<ptr->info<<endl;
		ptr = ptr->link;
    }
    
    return 0;
}
