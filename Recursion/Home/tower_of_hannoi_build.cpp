#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack <int> a;
    stack <int> b;
    stack <int> c;

    int n,i,brick;
    cout<<"how many bricks you wanted"<<endl;
    cin>>n;

    cout<<"input the brick size in integer format in Descending Order"<<endl;

    for(i=1;i<=n;i++){
        cin>>brick;
        if(i>1 && a.top()>brick){
            a.push(brick);
        }
        else{
            a.push(brick);
        }

    }



    return 0;
}
