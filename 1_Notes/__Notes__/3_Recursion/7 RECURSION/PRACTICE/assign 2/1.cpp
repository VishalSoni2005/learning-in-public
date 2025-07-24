#include<bits/stdc++.h>
using namespace std;
void printingReverse(vector<int>&nums, int idx){
    if(idx==nums.size()) return;
    printingReverse(nums,idx+1);
    cout<<nums[idx]<<" ";
}
int main(){
    int n;
    cout<<"Size of array : ";
    cin>>n;
    vector<int>v(n);
    cout<<"fill : ";
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    printingReverse(v,0);
}