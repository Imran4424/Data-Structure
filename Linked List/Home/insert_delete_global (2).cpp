#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *start = new node;

void show();

void options()
{
    cout<<"Input 1 to insert node"<<endl;
    cout<<"Input 2 to delete node"<<endl;
    cout<<"Input 3 to search list"<<endl;
    cout<<"Input 4 to sort list data"<<endl;
    cout<<"Input 5 to display the list"<<endl;
    cout<<"Input 0 to terminate operation"<<endl;
}

void opps()
{
    cout<<"Input 1 to action at start list"<<endl;
    cout<<"Input 2 to action at end of list"<<endl;
}

void insert_at_end(int num)
{
    int i,info;

    for(i=1; i<=num; i++)
    {
        cin>>info;
        node *temp = new node;
        temp->data = info;
        temp->next = NULL;

        if(start == NULL)
        {
            start = temp;
        }
        else
        {
            node *ptr = start;

            while(ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = temp;
        }
    }
    show();
}


void insert_at_start(int num)
{
    int i,info;

    for(i=1; i<=num; i++)
    {
        cin>>info;
        node *temp = new node;
        temp->data = info;
        temp->next = start;
        start = temp;

        /*   if(start == NULL){
               start = temp;
               start->next = NULL;
           }
           else{
               node *ptr = start;
               temp->next = ptr;
               ptr = temp;
           } */

    }
    show();
}

int delete_at_end(int num)
{
    int i;

    for(i=1; i<=num; i++)
    {
        node *ptr = start;
        if(ptr == NULL)
        {
            cout<<"Sorry,List is empty"<<endl;
            return 0;
        }
        else if(ptr->next == NULL)
        {
            ptr = NULL;
            return 0;
        }
        else
        {
            while(ptr->next->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = NULL;
        }
    }
    show();
    return 0;
}

int delete_at_start(int num)
{
    int i;

    for(i=1; i<=num; i++)
    {
        node *ptr = start;
        if(start == NULL)
        {
            cout<<"Sorry,List is empty"<<endl;
            return 0;
        }
        else if(start->next == NULL)
        {
            start = NULL;
            return 0;
        }
        else
        {
            start = start->next;
        }
    }
    show();
    return 0;
}

void search_list(int info)
{
    node *ptr = start;
    int pos = 0;

    while(ptr != NULL)
    {
        if(ptr->data == info)
        {
            pos = 1;
            break;
        }
        ptr = ptr->next;
    }
    cout<<"Searched Data found in the list"<<endl;
}

void sort_list_data()
{
    cout<<"Sorry,system unavailable for the moment"<<endl;
}

void show()
{
    node *ptr = start;

    cout<<endl;
    while(ptr != NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl<<endl;
}

int main()
{
    start = NULL;
    int indicate,i,desired_num;

    while(1)
    {
        options();
        cin>>indicate;
        int choice;

        if(indicate==1)
        {
            cout<<"how many nodes"<<endl;
            cin>>desired_num;
            opps();
            cin>>choice;
            if(choice==1)
            {
                insert_at_start(desired_num);
            }
            else if(choice==2)
            {
                insert_at_end(desired_num);
            }

        }
        else if(indicate==2)
        {
            cout<<"how many nodes"<<endl;
            cin>>desired_num;
            opps();
            cin>>choice;
            if(choice==1)
            {
                delete_at_start(desired_num);
            }
            else if(choice==2)
            {
                delete_at_end(desired_num);
            }
        }
        else if(indicate==3)
        {
            int n;
            cout<<"Enter your number"<<endl;
            cin>>n;
            search_list(n);
        }
        else if(indicate==4)
        {
            sort_list_data();
        }
        else if(indicate==5)
        {
            show();
        }
        else if(indicate == 0)
        {
            break;
        }
    }

    return 0;
}
