#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int m,n,i,j;
    cout<<"Insert matrix size"<<endl;
    cin>>m>>n;
    int mat[m][n];

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cout<<setw(2)<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    int larray[100],k=0,array_end;

    for(i=0;i<m;i++){
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
