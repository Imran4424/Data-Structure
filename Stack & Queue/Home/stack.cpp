#include <iostream>
using namespace std;

int n;


class Stack{

    int *a = new int[n];
    int top;

public:

    Stack()
    {
        top = -1;
    }
    void push(int val);
    int pop();

};


void Stack :: push(int val)
{
    if(top == n-1){
        cout<<endl<<"Stack Overflow"<<endl<<endl;
    }
    else{
        top++;
        a[top] = val;
    }

}

void disop()
{
    cout<<"Input 1 to push"<<endl;
    cout<<"Input 2 to pop"<<endl;
    cout<<"Input 3 to terminate"<<endl;
}

int Stack :: pop()
{
    int temp;
    if(top == -1){
        cout<<endl<<"Stack Underflow"<<endl<<endl;;
        return 0;
    }
    else{
        temp = a[top];
        top--;
    }
    return temp;
}


int main()
{
    cout<<"input stack size"<<endl;
    cin>>n;

    Stack obj;

    int indication,info,pot;
    while(1){
        disop();
        cin>>indication;

        if(indication==1){
            cout<<"input your value to push"<<endl;
            cin>>info;
            obj.push(info);
        }
        else if(indication==2){
            pot = obj.pop();
            if(pot!=0){
                cout<<pot<<endl;
            }

        }
        else if(indication==3){
            break;
        }

    }

    return 0;
}
