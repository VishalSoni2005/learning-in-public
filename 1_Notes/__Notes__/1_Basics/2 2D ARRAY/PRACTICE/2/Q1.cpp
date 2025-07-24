#include<iostream>
#include<climits>
using namespace std;
// void input(int m,int n ,int a[m][n]){
//     //Input
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//             cin>>arr[i][j];
//         }
//     }
//     return;

// }
// void display(int m,int n, int arr[m][n]){

// }
int main(){
    int m;
    cout<<"Enter no of Row : ";
    cin>>m;
    int n;
    cout<<"Enter no of Cols : ";
    cin>>n;
    int arr[m][n];
    //input(m,n,arr[m][n]);
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    //display(arr[m][n] , m , n);

    //OUTPUT
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    //FINDING MAXIMUM
    int a = INT_MIN;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]>a) a = arr[i][j];
        }
    }
    cout<<a;


}