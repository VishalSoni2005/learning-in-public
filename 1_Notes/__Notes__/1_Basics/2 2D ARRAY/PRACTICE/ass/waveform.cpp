#include<bits/stdc++.h>
using namespace std;
void swap(int a , int b){
    int temp = a;
    a=b;
    b=temp;
}
int main(){
    int n;
    cin>>n;
    cout<<"Fill the matrix "<<endl;
    int arr[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>arr[i][j];
        }
    }
    cout<<endl;
    //spiral
    for(int i=0;i<n;i++){
        if(i%2==0){
            for(int j=0;j<n;j++){
                cout<<arr[i][j]<<" ";
            }
        }
        else{
            for(int j=n-1;j>=0;j--){
                cout<<arr[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}