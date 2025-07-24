#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[2][4];
    cout<<"enter the roll no. : ";

        for(int j=0;j<4;j++){
            cin>>arr[0][j];
        }
    
    cout<<"enter marks obtained : ";
        for(int j=0;j<4;j++){
            cin>>arr[1][j];
        }
    
    cout<<endl;
    cout<<"Roll no of student is : ";
    
        for(int j=0;j<4;j++){
            cout<<arr[0][j]<<" ";
        }
    
    cout<<endl;
    cout<<"marks obtained by the student is : ";
    
        for(int j=0;j<4;j++){
            cout<<arr[1][j]<<" ";
        }
    }
    



















    //     //first step is to take transpose
    //     int m = matrix[0].size();
    //     for(int i=0;i<m;i++){
    //         for(int j=i+1;j<m;j++){
    //             int temp = matrix[i][j];
    //             matrix[i][j] = matrix[j][i];
    //             matrix[j][i] = temp;
    //     }
    // }
    // //now reprinting
    // for(int k=0;k<m;k++){
    //     int i=0;
    //     int j=m-1;
    //     while(i<=j){
    //         int temp = matrix[k][i];
    //         matrix[k][i] = matrix[k][j];
    //         matrix[k][j] = temp;
    //         i++;
    //         j--;
    //     }
    // }
    // return;