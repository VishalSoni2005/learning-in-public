#include<iostream>
#include<climits>
using namespace std;
int main(){
    int m;
    cout<<"Enter no of Row or colums : ";
    cin>>m;

    int arr[m][m];
    //INPUT
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    cout<<endl;
    //printing
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    //TAKING TRANSPOSE  IN SAME MATRIX
    for(int i=0;i<m;i++){
        for(int j=i+1;j<m;j++){
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
    //PRINTING
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

}