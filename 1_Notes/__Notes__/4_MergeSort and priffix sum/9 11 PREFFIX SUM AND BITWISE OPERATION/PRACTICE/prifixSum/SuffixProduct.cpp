#include<bits/stdc++.h>
using namespace std;
void display(vector<int>&ans){
    cout<<"Your suffix Sumed Array is : ";
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
}
void reverseArray(vector<int>&ans , int n){
    int i = 0;
    int j = n-1;
    while(i<j) {
        int temp = ans[i];
        ans[i] = ans[j];
        ans[j] = temp;
        i++;
        j--;
    }
}
void prifixproduct(vector<int>&ans,int n){
    for(int i=1;i<n;i++){
        ans[i] *= ans[i-1];
    }
}
int main(){
    int n;
    cout<<"Size : ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Fill : ";
    for(int i=0;i<n;i++) cin>>arr[i];
    reverseArray(arr,n);
    prifixproduct(arr,n);
    reverseArray(arr,n);
    display(arr);
}