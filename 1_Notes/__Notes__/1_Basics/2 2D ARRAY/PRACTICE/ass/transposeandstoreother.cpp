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

    //transposing
    int brr[n][n];
    for(int i=0;i<n;i++){
        for(int j=n-1;j>=0;j--){
              brr[i][j] = arr[j][i];
        }
    }
    // printing
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
             cout<<brr[i][j]<<" ";
        }
        cout<<endl;
    }
}