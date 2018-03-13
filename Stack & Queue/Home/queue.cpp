#include <iostream>
using namespace std;

int n;

class Queue{

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
        if(((rear+1)%n)==front){
            cout<<endl<<"Overflow"<<endl<<endl;
        }
        else if(front==-1 && rear==-1){
            rear = 0;
            front = 0;

        }
        else{
            rear = (rear+1)%n;
        }
        a[rear] = val;
    }
    void pop()
    {
        if(front==-1 && rear==-1){
            cout<<endl<<"Underflow"<<endl<<endl;
        }
        else if(front==rear){
            cout<<a[front]<<endl;
            front=rear=-1;
        }
        else{
            if(front==n-1){
                front = -1;
            }
            cout<<a[front]<<endl;

            front = (front+1)%n;
        }
    }

};

void disop()
{
    cout<<"Input 1 to push"<<endl;
    cout<<"Input 2 to pop"<<endl;
    cout<<"Input 3 to terminate"<<endl;
}

int main()
{
    cout<<"input Queue size"<<endl;
    cin>>n;

    Queue obj;

    int indication,info;
    while(1){
        disop();
        cin>>indication;

        if(indication==1){
            cin>>info;
            obj.push(info);
        }
        else if(indication==2){
            obj.pop();
        }
        else if(indication==3){
            break;
        }

    }

    return 0;
}
