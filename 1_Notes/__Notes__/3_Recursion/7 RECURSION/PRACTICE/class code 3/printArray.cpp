#include<bits/stdc++.h>
using namespace std;
void printArray(int arr[],int n,int idx){
    if(idx==n) return;
    cout<<arr[idx]<<" ";
    printArray(arr,n,idx+1);
}
void printvector(vector<int>v,int idx){
    if(idx==v.size()) return;
    cout<<v[idx]<<" ";
    printvector(v,idx+1);
}
int main(){
    int n;
    cout<<"Size of array : ";
    cin>>n;
    // vector<int>v(n);
    // cout<<"Fill the Array : ";
    // for(int i=0;i<n;i++){
    //     cin>>v[i];
    // } 
    // printvector(v,0);
    int arr[n];
    cout<<"Fill the Array : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Your Array sir : ";
    printArray(arr,n,0);
}