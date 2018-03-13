#include <iostream>
#include <iomanip>
using namespace std; /// adjacency matrix and path matrix of fig 8.3 of example 8.3

int main()
{
    int n,i,j,sum,k;
    cout<<"Number of nodes"<<endl;
    cin>>n;

    int mat[n][n],mat2[n][n],mat3[n][n],mat4[n][n],B[n][n],path[n][n],flag;

    cout<<"Input your adjacency matrix"<<endl;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }

    cout<<endl<<"mat:"<<endl<<endl;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<setw(2)<<mat[i][j]<<" ";
        }
        cout<<endl;
    }


    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            sum = 0;
            for(k=0;k<n;k++){
                sum += mat[i][k]*mat[k][j];
            }
            mat2[i][j] = sum;
        }
    }

    cout<<endl<<"mat2:"<<endl<<endl;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<setw(2)<<mat2[i][j]<<" ";
        }
        cout<<endl;
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            sum = 0;
            for(k=0;k<n;k++){
                sum += mat2[i][k]*mat[k][j];
            }
            mat3[i][j] = sum;
        }
    }

    cout<<endl<<"mat3:"<<endl<<endl;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<setw(2)<<mat3[i][j]<<" ";
        }
        cout<<endl;
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            sum = 0;
            for(k=0;k<n;k++){
                sum += mat3[i][k]*mat[k][j];
            }
            mat4[i][j] = sum;
        }
    }

    cout<<endl<<"mat4:"<<endl<<endl;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<setw(2)<<mat4[i][j]<<" ";
        }
        cout<<endl;
    }

    for(i=0;i<n;i++){

        for(j=0;j<n;j++){
            B[i][j] = (mat[i][j]+ mat2[i][j]+ mat3[i][j]+ mat4[i][j]);
        }
    }

    cout<<endl<<"B:"<<endl<<endl;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<setw(2)<<B[i][j]<<" ";
        }
        cout<<endl;
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(B[i][j]!= 0){
                path[i][j] = 1;
            }
            else{
                path[i][j] = 0;
            }
        }
    }

    cout<<endl<<"path:"<<endl<<endl;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<setw(2)<<path[i][j]<<" ";
        }
        cout<<endl;
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(path[i][j] == 0){
                flag = 0;
                i = n;
                break;
            }
        }
    }

    if(flag){
        cout<<endl<<"Graph is strongly connected"<<endl;
    }
    else{
        cout<<endl<<"Graph is not strongly connected"<<endl;
    }

    return 0;
}
