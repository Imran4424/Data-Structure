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
    int pop()
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


};



int main()
{
    char str[20];
    cin>>str;
    cout<<str<<endl;;
    Stack <int> obj(20);
    int pot,i,a=5,b=6,c=2,d=3,x,y;

    i=0;
    while(str[i] != '\0'){
        if(str[i]=='a'){
            obj.push(a);
        }
        else if(str[i]=='b'){
            obj.push(b);
        }
        else if(str[i]=='c'){
            obj.push(c);
        }
        else if(str[i]=='d'){
            obj.push(d);
        }
        else if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/'){
            y = obj.pop();
            x = obj.pop();

            cout<<x<<" "<<y<<endl;

            switch(str[i]){
                case '+':
                    pot = x+y;
                    break;

                case '-':
                    pot = x-y;
                    break;

                case '*':
                    pot = x*y;
                    break;

                case '/':
                    pot = x/y;
                    break;
            }

            obj.push(pot);
        }

        i++;
    }

    cout<<obj.pop()<<endl;

    return 0;
}

