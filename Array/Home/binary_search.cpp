#include <iostream>
using namespace std; //ei code ta sudhu ascending order er jonno

int a[100],element = -1;

void display()
{
    int i;

    for(i=0; i<=element; i++)
    {
        cout<<a[i]<<" ";

    }
    cout<<endl;

}

int sorting()
{
    int indicate,i,j,temp;
    cout<<"Pick your choice\n"<<endl;
    cout<<"1.Ascending"<<endl<<"2.Descending"<<endl;
    cin>>indicate;


    if(element>0)
    {
        if(indicate==1)
        {
            for(i=0; i<=element; i++)
            {
                for(j=0; j<=element-i-1; j++)
                {
                    if(a[j]>a[j+1])
                    {
                        temp=a[j];
                        a[j]=a[j+1];
                        a[j+1]=temp;
                    }
                }
            }
        }

        if(indicate==2)
        {
            for(i=0; i<=element; i++)
            {
                for(j=0; j<=element-i-1; j++)
                {
                    if(a[j]<a[j+1])
                    {
                        temp=a[j];
                        a[j]=a[j+1];
                        a[j+1]=temp;
                    }
                }
            }

        }
    }
    if(element==-1)
    {
        cout<<"Array is empty"<<endl;
    }

    display();
    return 0;
}

void searching()
{

}

int main()
{
    int i,up,low,mid,n;

    cout<<"Array size"<<endl;
    cin>>n;
    element = n-1;

    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    display();

    sorting();

    cout<<"Insert the num to be search"<<endl;
    int num;

    cin>>num;

    low = 0;
    up = n -1;
    mid = (up+low)/2;

    while(1)
    {
        if(a[mid] == num)
        {
            cout<<num<<" is found in the array"<<endl;
            break;
        }

        if(a[mid]>num)
        {
            up = mid-1;
            mid = (low+up)/2;
        }

        if(a[mid] < num)
        {
            low = mid+1;
            mid = (low+up)/2;
        }

        if((low>=up))
        {
            if(a[mid] != num)
            {
                cout<<num<<" not found in the array"<<endl;
                break;
            }

        }
    }

    return 0;
}
