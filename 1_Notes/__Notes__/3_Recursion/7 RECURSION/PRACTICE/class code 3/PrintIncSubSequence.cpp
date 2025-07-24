//FOR INCREASING PATTERN ARRAY MUST BE SORTED
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void IncSubSeq(vector<int>&v,int n,int idx,int size,vector<int>ans){
    if(idx==n){
        if(ans.size() == size){
            for(int i=0;i<ans.size();i++){
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    IncSubSeq(v,n,idx+1,size,ans);
    ans.push_back(v[idx]);
    IncSubSeq(v,n,idx+1,size,ans);
}
int main(){
    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    cout<<"Fill the array : ";
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int k;
    cout<<"Enter size of subsequence : ";
    cin>>k;
    sort(v.begin() , v.end());
    vector<int>ans;
    IncSubSeq(v,n,0,k,ans);
}