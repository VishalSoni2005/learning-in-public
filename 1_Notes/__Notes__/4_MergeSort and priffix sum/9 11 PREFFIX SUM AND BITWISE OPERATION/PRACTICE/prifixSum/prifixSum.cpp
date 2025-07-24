#include<bits/stdc++.h>
using namespace std;
void display(vector<int>&ans){
    cout<<"Your prifix Sumed Array is : ";
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
}
vector<int> prifixSum(vector<int>&ans , int n){
    for(int i=1;i<n;i++){
        ans[i] +=  ans[i-1];
    }
    display(ans);
}
int main(){
    int n;
    cout<<"Size : ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Fill : ";
    for(int i=0;i<n;i++) cin>>arr[i];
    prifixSum(arr,n);
}