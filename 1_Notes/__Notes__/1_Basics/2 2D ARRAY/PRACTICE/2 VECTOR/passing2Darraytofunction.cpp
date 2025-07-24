#include <iostream>
#include <vector>
using namespace std;
//ROW AND COLUMUN MUST BE GIVEN TO PASS 2D ARRAY [LIMITATION] , THAT IS WHY 2D VECTORS ARE USED
// AISE NHI CHALEGA  -> void change(int arr[m][n],int m, int n);   WRONG
void change(int arr[3][3]){
    arr[0][0] = 99;

}
void print(int arr[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int main(){
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    print(arr);
    change(arr);
    print(arr);
}