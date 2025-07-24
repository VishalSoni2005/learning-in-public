#include<iostream>
#include<vector>
using namespace std;
void ArraySubset(vector<int>& original , int n , int idx , vector<int>ans){
    if(idx == n){
        vector<vector<int>>final;
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return;
    }
    int element = original[idx];
    ArraySubset(original,n,idx+1,ans);
    ans.push_back(element);
    ArraySubset(original,n,idx+1,ans); 
}

int main(){
    int n;
    cout<<"Size Of A Vector : ";
    cin>>n;
    cout<<"Fill the Vector : ";
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<"Subset are following : "<<endl;
    vector<int>ans;
    ArraySubset(v,n,0,ans);
}