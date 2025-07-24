//MATHEMATICAL FORMULA IS 2*ans[i] == ans[n-1]
#include<bits/stdc++.h>
using namespace std;
void partition(vector<int>&ans){
    int n = ans.size();
    int idx = -1;
    for(int i=1;i<n;i++){
        if(2*ans[i] == ans[n-1]){
            idx = i;
            break;
        }
    }
    if(idx == -1) cout<<"The given array cant be partitioned ";
    else cout<<"It can be partitioned form "<<idx;
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
    prifixSum(arr,n);
    partition(arr);
}