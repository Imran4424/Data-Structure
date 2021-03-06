#include <iostream>
using namespace std;

struct node{
	int data;
	struct node *next;
};

void insertnode_at_end (node **ptr, int val){
	node *temp = new node;
	temp->data=val;
	temp->next=NULL;
	if(*ptr==NULL) *ptr=temp;
	else{
		node *temp1;
		temp1=*ptr;
		while(temp1->next!=NULL)
			temp1=temp1->next;
		temp1->next=temp;
	}
}

int  delete_at_end(node **ptr){
	node *temp;
	temp=*ptr;
	if(*ptr==NULL){
		cout<<endl<<"Sorry,the list is empty  :( "<<endl;
		 return 0;
	}
	else if(temp->next==NULL) *ptr=NULL;
	else{
		while(temp->next->next!=NULL){
			temp=temp->next;
		}
		temp->next=NULL;
	}
	return 0;
}

int  display(node *ptr){
	node *temp;
	temp=ptr;
	if(temp==NULL){
		cout<<"\nempty list :(\n";
	}
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
	return 0;
}

void display()
{
	cout<<"Input 1 to insert"<<endl;
	cout<<"Input 2 to delete"<<endl;
	cout<<"Input 3 to display"<<endl;
	cout<<"Input 4 to display frequency"<<endl;
	cout<<"Input 5 to break"<<endl;
	
}

int main()
{
	node *ptr = NULL;
	int indicate,i;
	
	while(1){
		display();
		cin>>indicate;
		
		if(indicate==1){
			cout<<"input data"<<endl;
			cin>>i;
			insertnode_at_end (&ptr,i);
		}
		if(indicate==2){
			delete_at_end(&ptr);
		}
		if(indicate==3){
			display(ptr);
		}
		if(indicate==5){
			break;
		}
		
	}
	return 0;
}
