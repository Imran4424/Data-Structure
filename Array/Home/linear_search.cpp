#include <iostream>
using namespace std;

int main()
{
    int a[10];

    for(int i=0;i<10;i++)
    {
        cin>>a[i];
    }

    cout<<"Enter the desired value"<<endl;

    int num,flag = 0;
    cin>>num;

    for(int i=0;i<10;i++)
    {
        if(a[i] == num)
        {
            flag = 1;
            break;
        }
    }

    if(flag)
    {
        cout<<"num is in the array"<<endl;
    }
    else
    {
        cout<<"num is not in the array"<<endl;
    }

    return 0;
}
