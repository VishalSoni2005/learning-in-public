#include <iostream>
using namespace std;
int main(){
    int arr[]= {1,2,9,4,5,6};
    int max = arr[0];
    for(int i=0;i<6;i++){
        if(arr[i] <arr[i+1])  max = arr[i+1];
        }
        cout<<max;
}