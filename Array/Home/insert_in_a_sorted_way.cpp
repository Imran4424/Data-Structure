#include <iostream>
using namespace std;

int main()
{
    int a[100],num,element = -1,i,j,target;

    while(cin>>num){
        i=0;
        if(num == -11){
            break;
        }
        if(element = 0){
            a[0] = num;

        }
        else{

            while(num>a[i] && i<element){
                target = i+1;
                i++;
            }

            if(target == element+1){
                a[target] = num;

            }
            else{
                for(i=element;i>=target;i--){
                    a[i+1] = a[i];
                }
                a[target] = num;

            }
        }

        for(i=0;i<=element;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;

        element++;

    }

    return 0;
}
