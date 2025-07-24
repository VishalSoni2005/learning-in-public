#include<iostream>
using namespace std;
int main(){
    //TRANSPOSE OF A SQUARE MATRIX
    int n;
    cout<<"Enter sides of matrix : ";
    cin>>n;
    int a[n][n];
    cout<<"Fill the matrix "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    cout<<endl;
    //transposing
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int temp = a[i][j] ;
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
































    // int m,n;
    // cout<<"Enter row and column no. using space : " ;
    // cin>>m>>n;
    // cout<<"Enter your first matrix : ";
    // cout<<endl;
    // int a[m][n];
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         cin>>a[i][j];
    //     }
    // }

    // int trans[n][m];
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         trans[j][i]=a[i][j];
    //     }
    // }
    // cout<<endl;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<trans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

}