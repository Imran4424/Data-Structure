#include <iostream>
using namespace std;

int main()
{
    int n,i,j;
    cout<<"Insert matrix size"<<endl;
    cin>>n;
    int mat[n][n];

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    int larray[100],k=0,array_end;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(mat[i][j] != 0){
                larray[k]= mat[i][j];
                k++;
            }
        }
        larray[k]=0;
        array_end = k;
        k++;
    }

    for(i=0;i<=array_end;i++){
        cout<<larray[i]<<" ";
    }
    cout<<endl;

    return 0;
}
