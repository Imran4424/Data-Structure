#include <iostream>
using namespace std;

int main()
{
    int num,i,element=0,target,a[100];

    while(cin>>num){
        if(num==-111){
            break;
        }
        if(element==0){
            a[0]=num;
        }
        else{
            for(i=0;i<=element;i++){
                if(a[i]>num){
                    target=i;
                    break;
                }
                else{
                    target=i+1;
                }
            }
            if(element+1==target){
                a[target]=num;
            }
            else{
                for(i=element;i>=target;i--){
                    a[i+1]=a[i];
                }
                a[target]=num;
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
