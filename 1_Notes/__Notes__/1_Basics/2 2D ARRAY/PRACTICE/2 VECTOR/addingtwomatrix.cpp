#include<iostream>
using namespace std;
int main(){
    cout<<"Enter your first matrix : ";
    int a[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>a[i][j];
        }
    }
    cout<<"Enter your second matrix : ";
    int b[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>b[i][j];
        }
    }
    //IF BOTH ROW AND COLUMN OF BOTH THE MATRIX ARE SAME THEN ONLLY ADD
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            a[i][j] += b[i][j];
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}