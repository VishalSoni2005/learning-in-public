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

    int arr1[m][n];
    //INPUT
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr1[i][j];
        }
    }


    int a;
    cout<<"Enter no of Row for second : ";
    cin>>a;
    int b;
    cout<<"Enter no of Cols for second : ";
    cin>>b;

    int arr2[a][b];
    //INPUT
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin>>arr2[i][j];
        }
    }

    //adding both matrix
    int p=m;
    int q=n;
    int arr3[p][q];
    if(m==a && n==b){
        for(int i=0;i<p;i++){
            for(int j=0;j<q;j++){
                arr3[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
}


    //printing
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr3[i][j]<<" ";
        }
        cout<<endl;
    }


}