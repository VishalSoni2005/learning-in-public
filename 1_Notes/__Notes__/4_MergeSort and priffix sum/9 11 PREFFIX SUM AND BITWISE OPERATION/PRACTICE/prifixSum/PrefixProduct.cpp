//  PRE(i) = arr(i) * arr(i-1) 
#include<bits/stdc++.h>
using namespace std;
vector<int> prifixProductIncludingCurrent(vector<int>&ans , int n){
    for(int i=1;i<n;i++){
        ans[i] *=  ans[i-1];
    }
}
vector<int>prifixProductExcludingCurrent(vector<int>&nums){
    int n = nums.size();
    vector<int>pre(n);
    vector<int>ans(n);
    //excluding 
    int p = nums[0];
    pre[0] = 1;
    for(int i=1;i<n;i++){
        pre[i] = p;
        p *= nums[i];
    }
}
int main(){
    int n;
    cout<<"Size : ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Fill : ";
    for(int i=0;i<n;i++) cin>>arr[i];
    prifixProductIncludingCurrent(arr,n);
   // prifixProductExcludingCurrent(arr);
    cout<<"Prifix Product : ";
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    
}