#include<bits/stdc++.h>
using namespace std;
int main(){
    int row1 , col1;
    cout<<"Enter row of first : ";
    cin>>row1;
    cout<<"Enter column of first : ";
    cin>>col1;
    int arr[row1][col1];
    cout<<"Fill the array : "<<endl;
    //Input of first
    for(int i=0;i<row1;i++)    for(int j=0;j<col1;j++)    cin>>arr[i][j];
    int row2 , col2;
    cout<<"Enter row of second : ";
    cin>>row2;
    cout<<"Enter column of second : ";
    cin>>col2;
    int brr[row2][col2];
    cout<<"Fill the array : "<<endl;
    //Input of second
    for(int i=0;i<row2;i++)    for(int j=0;j<col2;j++)    cin>>brr[i][j];

    ///////
    if(col1 == row2){
        int res[row1][col2];
        for(int i=0;i<row1;i++){
            for(int j=0;j<col2;j++){
                res[i][j] = 0;
                for(int k=0;k<row2;k++){
                    res[i][j] += arr[i][k] * brr[k][j];
                }
            }
        }
        for(int i=0;i<row1;i++) {
            for(int j=0;j<col2;j++) {
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else cout<<"SYNTAX ERROR";
}