#include<iostream>
#include<climits>
using namespace std;
void display(int arr[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j]<<" ";
        }
    }

}
void input(int arr[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }
    }
}
int main(){
    int arr[3][3];
    input(arr);
    int a = 0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            a += arr[i][j];
        }
    }
    cout<<a;
}