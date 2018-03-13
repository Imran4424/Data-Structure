#include<bits/stdc++.h>
#include <iostream>
using namespace std;

template <class var>
class Stack{

    int n;
    var *a;
    int top;

public:

    Stack(int val)
    {
        a = new var[val];
        n = val;
        top = -1;
    }
    void push(int val)
    {
        if(top == n-1){
            cout<<endl<<"Stack Overflow"<<endl<<endl;
        }
        else{
            top++;
            a[top] = val;
        }

    }
    void pop()
    {
        if(top == -1){
            cout<<endl<<"Stack Underflow"<<endl<<endl;;
        }
        else{

            top--;
        }
    }

    void Show() {
        for(int i=0; i<=top; i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }

    bool Is_empty() {
        return (top== -1)?1:0;
    }

    char Top() {
        if(top== -1) cout<<"Upps........ the stack is empty"<<endl;
        else return a[top];
        return -1;
    }


};

template <class api>
class Queue{

public:
    int front,rear,n;
    api *a;
    Queue(int val)
    {
        n = val;
        a = new api[val];
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
    char pop()
    {
        char temp = '\0';
        if(front==-1 && rear==-1){
            cout<<endl<<"Underflow"<<endl<<endl;
        }
        else if(front==rear){
            temp = a[front];
            front=rear=-1;
        }
        else{
            if(front==n-1){
                front = -1;
            }
            temp = a[front];

            front = (front+1)%n;
        }

        return temp;
    }

    bool Is_empty() {
        return (front==-1 && rear==-1)?1:0;
    }

};

int isoperator(char e) { // dekhbo operator ki na
    if(e == '+' || e == '-' || e == '*' || e == '/' || e == '%')
        return 1;
    else
        return 0;
}


int priority(char e)
{                           // priority matrik vabe dekha jabe
    int pri = 0;
    if(e == '*' || e == '/' || e =='%')
        pri = 2;
    else {
        if(e == '+' || e == '-')
            pri = 1;
    }
    return pri;
}

void infix_to_post(char infix[],char postfix[])
{
    Stack <char> sobj(45);

    Queue <char> qobj(45);

    int i=0;
    char n1;

    while(infix[i] != '\0'){
        while( isdigit(infix[i]) || isalpha(infix[i])) { // jotokhon kono sonkha ba char ache vorte thakbo postfix e
            qobj.push(infix[i]);
            i++;
        }
        if( infix[i] == '(' ) { // bam braket pele stack e push kore dibo
            sobj.push('(');
            i++;
        }
        if( infix[i] == ')') { // jokhon dan bracket pabo  stack e bam bracket paoar age porjonto sob pop kore postfix e rakhbo
            n1 = sobj.Top();
            while( n1 != '(' ) {
                qobj.push(n1);
                sobj.pop();
                n1 = sobj.Top();
            }
            sobj.pop();

            i++;
        }
        if( isoperator(infix[i]) ) { // jodi operator pai
            if(sobj.Is_empty()){
                sobj.push(infix[i]); // jodi stack khali hoy to push kore dibo
            }
            else {
                n1 = sobj.Top();     // soman ba besi prioritir jara ache tader sobaike pop kore postfix e likhe dibo
                while(!(priority(n1)<priority(infix[i]))) {
                    qobj.push(n1);

                    sobj.pop();
                    if(sobj.Is_empty()) break; // jodi khali hoe jay to break
                    n1 = sobj.Top();
                }
                sobj.push(infix[i]);
            }
            i++;
        }

    }

    while(!sobj.Is_empty()) {
        n1 = sobj.Top();

        qobj.push(n1);

        sobj.pop();
    }

    i = 0;

    while(!qobj.Is_empty()){
        postfix[i] = qobj.pop();
        i++;
    }
    postfix[i]='\0';
}

int main()
{
    char in[50],post[50];


    cout<<"Input your infix expression"<<endl;
    cin>>in;
    infix_to_post(in,post);

    cout<<post<<endl;


    return 0;
}
