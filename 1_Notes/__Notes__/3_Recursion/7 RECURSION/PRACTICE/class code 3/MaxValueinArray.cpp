#include<bits/stdc++.h>
using namespace std;
void maxValue(int arr[],int n,int idx,int max){
    if(idx==n){
        cout<<"Max Element Is : "<<max;
        return;
    }
    if(arr[idx]>max) max = arr[idx];
    maxValue(arr,n,idx+1,max);
}
int main(){
    int n;
    cout<<"Size of array : ";
    cin>>n;
    int arr[n];
    cout<<"Fill the Array : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    maxValue(arr,n,0,INT_MIN);
}