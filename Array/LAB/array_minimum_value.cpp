#include <iostream>
using namespace std;

int main()
{
    int a[30],i,temp=100000;

    for(i=0;i<30;i++){
        cin>>a[i];
    }
    for(i=0;i<30;i++){
        if(a[i]<temp){
            temp=a[i];
        }
    }

    cout<<"Minimum value is  "<<temp<<endl;

    return 0;
}

