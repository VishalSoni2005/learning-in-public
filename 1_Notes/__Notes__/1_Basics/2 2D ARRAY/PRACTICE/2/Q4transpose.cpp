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
    cout<<endl;
    //printing
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    //TAKING TRANSPOSE
    for(int j=0;j<n;j++){
        for(int i=0;i<m;i++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }


}