//ALGORITHM USED TO FIND SUFFIX SUM -> firstly reverse the whole array , secondly find prifixed summed array of reverse array , lastly reverse the prifixed sumed array
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
void prifixSum(vector<int>&ans,int n){
    for(int i=1;i<n;i++){
        ans[i] += ans[i-1];
    }
    reverseArray(ans,n);
}
int main(){
    int n;
    cout<<"Size : ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Fill : ";
    for(int i=0;i<n;i++) cin>>arr[i];
    reverseArray(arr,n);
    prifixSum(arr,n);
    display(arr);
}