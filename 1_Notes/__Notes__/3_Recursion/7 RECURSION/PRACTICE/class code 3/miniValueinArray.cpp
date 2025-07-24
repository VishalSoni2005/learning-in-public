#include<bits/stdc++.h>
using namespace std;
void minvlaue(int arr[],int n,int idx,int min){
    if(idx==n){
        cout<<"Min Element Is : "<<min;
        return;
    }
    if(arr[idx] < min) min = arr[idx];
    minvlaue(arr,n,idx+1,min);
   
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
    minvlaue(arr,n,0,INT_MAX);
}