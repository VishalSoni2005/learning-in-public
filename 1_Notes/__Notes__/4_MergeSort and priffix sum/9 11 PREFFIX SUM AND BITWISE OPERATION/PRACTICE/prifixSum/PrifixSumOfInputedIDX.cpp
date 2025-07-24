#include<bits/stdc++.h>
using namespace std;
int sum(int a , int b , vector<int>&ans){
    return ans[b] - ans[a-1]; 
}
vector<int> prifixSum(vector<int>&ans , int n){
    for(int i=1;i<n;i++){
        ans[i] +=  ans[i-1];
    }
    return ans;
}
int main(){
    int n;
    cout<<"Size : ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Fill : ";
    for(int i=0;i<n;i++) cin>>arr[i];
    int a , b;
    cout<<"Enter the idx of first tern (from where) : ";
    cin>>a;
    cout<<"Enter the idx of second tern (till where) : ";
    cin>>b;
    prifixSum(arr,n);
    cout<<"Sum of element of idx form "<<a<<" to "<<b<<" is "<<sum(a,b,arr);
}