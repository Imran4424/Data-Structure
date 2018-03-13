#include <iostream>
using namespace std;

int main()
{
    /// type 1

    pair<int,int> ar;

    cout<<"input int for first test"<<endl;

    int a,b;
    cin>>a>>b;

    ar.first = a;
    ar.second = b;


    //cout<<"1st type"<<endl;

    cout<<ar.first<<" "<<ar.second<<endl;

    /// test 2

    pair<string,string> love;

    cout<<"input string for second test"<<endl;

    cin>>love.first>>love.second;

    cout<<love.first<<" "<<love.second<<endl;

    /// test 3
    cout<<"Input name and money"<<endl;

    pair<string,double> account;

    string name;
    double balance;
    cin>>name>>balance;

    account = make_pair(name,balance);

    cout<<account.first<<" "<<account.second<<endl;


    return 0;
}
