#include <iostream>
using namespace std;

int main()
{
    int a[10],i,in=10,target,target2;

    for(i=0;i<=7;i++){
        a[i]=in;
        in+=10;
    }

    for(i=0;i<=7;i++){
        if(a[i]>54){
            target=i;
        }
        else{
            target=i+1;
        }
    }

    if(target==8){
        a[target]=54;
    }
    else{
        for(i=8;i>=target;i--){
            a[i+1]=a[i];
        }
        a[target]=54;
    }
    for(i=0;i<=8;i++){
        cout<<a[i]<<" ";
    }

    return 0;
}
