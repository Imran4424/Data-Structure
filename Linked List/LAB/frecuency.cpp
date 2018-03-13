 #include<bits/stdc++.h>

using namespace std;

struct node{
	int data ;
	struct node *next;
};

typedef node lit;

map<int ,int >tali;
map<int ,int >::iterator it;

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


bool  lin_ser(lit **head,int n){
	lit *temp;
	temp=*head;
	int fl=0;
	if(temp==NULL){
		cout<<"\nempty list :(\n";
	}
	while(temp!=NULL){
		if(temp->data==n) fl=1;
		temp=temp->next;
	}
	if(fl==0) return false;
	else return true;
	return 0;
}

void sortedInsert(lit **head_ref, int n)
{
	lit *new_node;
	new_node=(lit *)malloc(sizeof(lit));
	new_node->data=n;
        struct node* current;
        if (*head_ref == NULL || (*head_ref)->data >= new_node->data)
       {
          new_node->next = *head_ref;
         *head_ref = new_node;
       }
       else
      {
         current = *head_ref;
         while (current->next!=NULL &&current->next->data < new_node->data)
         {
             current = current->next;
         }
         new_node->next = current->next;
         current->next = new_node;
     }
}
 

int main(){
	lit *head = NULL;
	int n;
	cin>>n;
	while(n--){
		int i;
		cin>>i;
		seshe_jora(&head,i);
	}
	int k;
	cin>>k;
	if(true==lin_ser(&head,k)) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	show(head);
	
        lit *temp;
	temp=head;
	
	while(temp!=NULL){
		tali[temp->data]++;
		temp=temp->next;
	}
	
	cout<<"data"<<" "<<"frecuency"<<endl;
	for(it=tali.begin();it!=tali.end();it++){
		cout<<(it->first)<<"     "<<(it->second)<<endl; 
	}	

	cout<<endl;			
	return 0;
}
