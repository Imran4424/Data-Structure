#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout<<"Input array size"<<endl;

    int m,n,i,j,k,temp;
    cin>>m>>n;
    int a[m][n];

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cin>>a[i][j];
        }
    }

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cout<<setw(2)<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    for(k=0;k<(m*n);k++){

        for(j=0;j<n;j++){
            for(i=0;i<m-1;i++){

                if(a[i][j]>a[i+1][j]){
                    temp = a[i][j];
                    a[i][j] = a[i+1][j];
                    a[i+1][j] =temp;
                }
            }
            if(j!=n-1){
                if(a[m-1][j]>a[0][j+1]){
                    temp = a[m-1][j];
                    a[m-1][j] = a[0][j+1];
                    a[0][j+1] =temp;
                }
            }
        }
    }

    cout<<endl;

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cout<<setw(2)<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}



