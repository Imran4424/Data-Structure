#include <iostream>
#include <string>
using namespace std;


int main()
{
    int e,i,element=0;
    cout<<"insert your array size"<<endl;
    cin>>e;
    string a[e];


    for(i=0;i<e-2;i++){
        getline(cin,a[i]);
        element++;
    }

    cout<<endl<<endl;
    for(i=0;i<e-2;i++){
        cout<<a[i]<<endl;
    }

    cout<<endl<<endl;
    a[element]="Rahim";
    for(i=0;i<e-1;i++){
        cout<<a[i]<<endl;
    }

    return 0;
}
