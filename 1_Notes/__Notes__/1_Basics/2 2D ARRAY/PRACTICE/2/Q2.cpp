#include<iostream>
#include<climits>
using namespace std;
int main(){
    int m;
    cout<<"Enter no of Row : ";
    cin>>m;
    int n;
    cout<<"Enter no of Cols : ";
    cin>>n;

    int arr[m][n];
    //INPUT
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    //FINFING SUM
    int a=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            a += arr[i][j];
        }
    }
    cout<<a;
    //printing
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }


}