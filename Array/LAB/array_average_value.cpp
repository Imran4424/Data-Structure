#include <iostream>
using namespace std;

int main()
{
    int e,sum=0;
    cin>>e;
    int a[e],i;

    for(i=0;i<e;i++){
        cin>>a[i];
    }
    for(i=0;i<e;i++){
         sum+=a[i];

    }

    cout<<"Average value is  "<<(sum/e)<<endl;

    return 0;
}


