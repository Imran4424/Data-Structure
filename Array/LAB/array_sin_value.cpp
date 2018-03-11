#include <iostream>
#include <cmath>
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
        cout<<"Sin value is  "<<sin(a[i]*M_PI/180)<<endl;

    }

    return 0;
}




