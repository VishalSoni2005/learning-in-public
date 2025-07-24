#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"Row ";
    cin>>n;
    int arr[n][n];
    cout<<"Enter the matrix : ";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }   
    cout<<endl; 

    //wave printing
    for(int i=0;i<n;i++){
        if(i%2==0){
            for(int j=0;j<n;j++){
                cout<<arr[i][j]<<" ";
            }
        }
        else{
            for(int k=n-1;k>=0;k--){
                cout<<arr[i][k]<<" ";
            }
        }
        cout<<endl;      
    }
}
