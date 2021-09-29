#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef long long int lli;

int main()
{
    map<string,vector< pair<string,lli> > > table;

    string name,paired;
    lli boolean;

    for(lli i=1;i<=1;i++)
    {

        cin>>name>>paired>>boolean;

        table[name].push_back(make_pair(paired,boolean));
    }

    cout<<table[name][0].first<<" "<<table[name][0].second<<endl;

    return 0;
}
