#include <iostream>
using namespace std;

int a=0,b=1,temp;

void fibonacci(int end)
{
    if(a+b<end){
        cout<<a+b<<" ";
        temp=a;
        a=b;
        b=a+temp;
        fibonacci(end);
    }
    
}

int main()
{
    int end;
    cin>>end;
    
    cout<<a<<" "<<b<<" ";
    fibonacci(end);
    
    cout<<endl;

    return 0;
}
