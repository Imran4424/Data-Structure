#include <iostream>
using namespace std;

int main()
{
    int a[30],i,temp;

    for(i=0;i<30;i++){
        cin>>a[i];
    }
    temp = a[0];
    for(i=0;i<30;i++){
        if(a[i]>temp){
            temp=a[i];
        }
    }

    cout<<"Maximum value is  "<<temp<<endl;

    return 0;
}
