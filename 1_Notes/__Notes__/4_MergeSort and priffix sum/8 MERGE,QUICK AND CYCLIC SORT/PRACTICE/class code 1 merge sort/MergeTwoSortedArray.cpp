#include<bits/stdc++.h>
using namespace std;
void display(vector<int>&ans){
    cout<<"Answer is : ";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
void mergeArray(vector<int>&v1 , vector<int>&v2 , vector<int>&ans){
    int n = v1.size();
    int m = v2.size();
    int i = 0;
    int j = 0;
    int k = 0;
    while(i<n && j<m){
        if(v1[i] < v2[j]) {
            ans.push_back(v1[i]);
            i++;
        }
        else {
            ans.push_back(v2[j]);
            j++;
        }
    }
    if(i == n){
        while(j<m){
            ans.push_back(v2[j]);
            j++;
        }
    }
    if(j == m){
        while(i<n){
            ans.push_back(v1[i]);
            i++;
        }
    }
    display(ans);    
}
int main(){
    int n;
    cout<<"Enter size of first array : ";
    cin>>n;
    vector<int>arr1(n);
    cout<<"Fill the array : ";
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    sort(arr1.begin() , arr1.end());
    ///////////////////////////////////
    int m;
    cout<<"Enter size of second array : ";
    cin>>m;
    vector<int>arr2(m);
    cout<<"Fill the array : ";
    for(int i=0;i<m;i++){
        cin>>arr2[i];
    }
    sort(arr2.begin() , arr2.end());
    ////////////////////////////////////////
    vector<int>ans;
    mergeArray(arr1,arr2,ans);
    
}
