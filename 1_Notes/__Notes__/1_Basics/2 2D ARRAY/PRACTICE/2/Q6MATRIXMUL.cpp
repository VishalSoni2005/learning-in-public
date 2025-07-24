#include<iostream>
#include<climits>
using namespace std;
int main(){

    int m;
    cout<<"Enter no of Row for first : ";
    cin>>m;
    int n;
    cout<<"Enter no of Cols for first : ";
    cin>>n;

    int a;
    cout<<"Enter no of Row for second : ";
    cin>>a;
    int b;
    cout<<"Enter no of Cols for second : ";
    cin>>b;

    if(n==a){
    int arr1[m][n];
    cout<<"Enter elements of first matrix : "<<endl;
    //INPUT arr1
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr1[i][j];
        }
    }

    int arr2[a][b];
    cout<<"Enter elements of second matrix : "<<endl;
    //INPUT arr2
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin>>arr2[i][j];
        }
    }
    cout<<endl;

    //RESULTANT MATRIX
    int res[m][b];
    for(int i=0;i<m;i++){
        for(int j=0;j<b;j++){
            res[i][j] = 0;
            for(int k=0;k<n;k++){
                res[i][j] += arr1[i][k]*arr2[k][j];
            }
        }
    }
    //printing
    for(int i=0;i<m;i++){
        for(int j=0;j<b;j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }


}
    else{
        cout<<"Multiplication not possible ";
    }



}