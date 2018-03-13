 #include<bits/stdc++.h>

using namespace std;

struct node{
	int data ;
	struct node *next;
};

typedef node lit;

void seshe_jora(lit **head,int n){
	lit *temp = (lit *)malloc(sizeof(lit));
	temp->data=n;
	temp->next=NULL;
	if(*head==NULL) *head=temp;//mathay jora dilam
	else{
		lit *temp1;
		temp1=*head;
		while(temp1->next!=NULL) // lej khuje ber korchi
			temp1=temp1->next;
		temp1->next=temp; // lej e jora dilam
	}
}

int  seshe_delet(lit **head){
	lit *temp;
	temp=*head;
	if(*head==NULL){
		cout<<"\nUpps .. the list is empty  :( \n";
		 return 0;
	}
	else if(temp->next==NULL) *head=NULL;
	else{
		while(temp->next->next!=NULL){
			temp=temp->next;
		}
		temp->next=NULL;
	}
	return 0;
}

int suru_jora(lit **head,int n){
	lit *temp=(lit *)malloc(sizeof(lit));
	temp->data=n;
	temp->next=*head;
	*head=temp;
	return 0;
}

int suru_delet(lit **head){
	if(*head==NULL){
		 cout<<"\nUpps... the list is empty :( "<<endl;
		 return 0;
	}
	else{
		(*head)=(*head)->next;
	}
	return 0;
}


int  show(lit *head){
	lit *temp;
	temp=head;
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

int main(){
	lit *head = NULL;
	int n;
	cin>>n;
	while(n--){
		int i;
		cin>>i;
		suru_jora(&head,i);
	}
	show(head);
	suru_delet(&head);
	show(head);
	return 0;
}
