#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int lli;

bool binarysearch(vector<lli> ar,lli tar)
{
    sort(ar.begin(),ar.end());

    lli low = 0, high = ar.size() - 1;

    while(low <= high)
    {
        lli mid = (high+low) / 2;

        if(ar[mid] == tar)
        {
            return true;
        }
        else if(ar[mid] > tar)
        {
            high = mid-1;
        }
        else if(ar[mid] < tar)
        {
            low = mid + 1;
        }
    }

    return false;
}


int main()
{
    vector<lli> ar;

    cout<<"number of variables"<<endl;
    lli num;
    cin>>num;

    for(lli i=1;i<=num;i++)
    {
        lli temp;
        cin>>temp;

        ar.push_back(temp);
    }

    lli tar;
    cin>>tar;

    bool flag = binarysearch(ar,tar);

    if(flag)
    {
        cout<<"number is found"<<endl;
    }
    else
    {
        cout<<"number is not found"<<endl;
    }

    return 0;
}
