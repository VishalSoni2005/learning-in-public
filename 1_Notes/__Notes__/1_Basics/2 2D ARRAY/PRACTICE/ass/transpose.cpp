#include <iostream>
using namespace std;
int main(){
    int m;
    int n;
    cin>>m;
    cin>>n;
    int arr[m][n];
    cout<<"Enter the first matrix : ";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }   
    cout<<endl; 

    //transposing
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
              cout<<arr[j][i]<<" ";
        }
        cout<<endl;
    }
    //printing
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<arr[i][j]<<" ";
    //     }
        
    // }
}