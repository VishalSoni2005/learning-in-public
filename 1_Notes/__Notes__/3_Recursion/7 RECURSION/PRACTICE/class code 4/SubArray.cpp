#include<bits/stdc++.h>
using namespace std;
void SubArray(vector<int>&v,int n,int idx,vector<int>ans){
    if(idx == n){
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return;
    }
    //int element = v[idx];
    SubArray(v,n,idx+1,ans);
    if(ans.size() == 0 || v[idx-1] == ans[ans.size()-1]){
        ans.push_back(v[idx]);
        SubArray(v,n,idx+1,ans);
    }
}
int main(){
    //NOTE -> SUBARRAY IS CONTINOUS . IT IS 1,2  NOT 1,4
    int n;
    cout<<"Enter size of an Array : ";
    cin>>n;
    vector<int>v(n);
    cout<<"Fill the Array : ";
    for(int i=0;i<n;i++){
        cin>>v[i];
    } 
    cout<<"Sub-Array are the following : "<<endl;
    vector<int>ans;
    SubArray(v,n,0,ans);
}