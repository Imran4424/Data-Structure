#include <iostream>
using namespace std;

int queue_size = 0,n;

class Queue
{

public:
    int front,rear;
    int *a = new int[n];              //here n denotes the max array size;

    Queue()
    {
        front = -1;
        rear = -1;
    }
    void push (int val)
    {
        if(((rear+1)%n)==front)
        {
            cout<<endl<<"Overflow"<<endl<<endl;
        }
        else if(front==-1 && rear==-1)
        {
            rear = 0;
            front = 0;

        }
        else
        {
            rear = (rear+1)%n;
        }
        a[rear] = val;
    }
    void pop()
    {
        if(front==-1 && rear==-1)
        {
            cout<<endl<<"Underflow"<<endl<<endl;
        }
        else if(front==rear)
        {
            cout<<a[front]<<endl;
            front=rear=-1;
        }
        else
        {
            if(front==n-1)
            {
                front = -1;
            }
            cout<<a[front]<<endl;

            front = (front+1)%n;
        }
    }


    void display()
    {
        for(int i=front;i<(front+queue_size);i++)
        {
            cout<<a[i]<<" ";
        }

        cout<<endl<<endl;
    }

    void reverses()
    {
        if(front==-1 && rear==-1)
        {
            return;
        }

        int size = (front+queue_size) - front;

        int temp[size];

        for(int i = 0,j = (front+queue_size)-1; i<size,j>=0;i++,j--)
        {
            temp[i] = a[j];
        }

        rear = 0;
        front = 0;

        for(int i = 0;i<size;i++)
        {
            a[i] = temp[i];

            rear++;
        }
    }

};



void options()
{
    cout<<"Input 1 to push/insert/enqueue"<<endl;
    cout<<"Input 2 to pop/delete/dequeue"<<endl;
    cout<<"Input 3 to display"<<endl;
    cout<<"Input 4 to display number of elements on queue"<<endl;
    cout<<"Input 5 to reverse the queue"<<endl;
    cout<<"input 0 to terminate"<<endl;
}

int main()
{
    cout<<"input the queue size"<<endl;
    cin>>n;

    Queue obj;


    while(1)
    {
        options();
        int indication;

        cin>>indication;

        if(indication == 1)
        {
            cout<<"input data"<<endl;

            int data;
            cin>>data;

            obj.push(data);

            queue_size++;
        }
        else if(indication == 2)
        {
            obj.pop();

            queue_size--;
        }
        else if(indication == 3)
        {
            obj.display();
        }
        else if(indication == 4)
        {
            cout<<"Number of elements in this queue is: "<<queue_size<<endl;
        }
        else if(indication == 5)
        {
            obj.reverses();
        }
        else if(indication == 0)
        {
            break;
        }


    }


    return 0;
}
