#include <iostream>
#include <vector>
using namespace std;
void input(int arr[2][4]){
    for(int i=0;i<2;i++){
        for(int j=0;j<4;j++){
            cin>>arr[i][j];
        }
    }
}
void print(int res[2][4]){
    for(int i=0;i<2;i++){
        for(int j=0;j<4;j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }

}
void sum(int arr[2][4], int brr[2][4]){
    int res[2][4];
    for(int i=0;i<2;i++){
        for(int j=0;j<4;j++){
            res[i][j] = arr[i][j] + brr[i][j] ;
        }
    }
    print(res);

}
int main(){
    int arr[2][4];
    cout<<"Enter the first matrix : ";
    input(arr);
    int brr[2][4];
    cout<<"Enter the second matrix : ";
    input(brr);
    sum(arr,brr);
    

    
}