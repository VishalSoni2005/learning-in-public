#include <iostream>
using namespace std;
int main(){
    int m;
    cout<<"Enter no of Row for first : ";
    cin>>m;
    int n;
    cout<<"Enter no of Cols for first : ";
    cin>>n;

    int arr1[m][n];
    cout<<"Enter elements of first matrix : "<<endl;
    //INPUT arr1
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr1[i][j];
        }
    }
    cout<<endl;
    
    
}