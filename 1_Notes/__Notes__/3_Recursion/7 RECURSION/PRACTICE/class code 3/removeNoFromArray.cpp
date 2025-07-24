#include<iostream>
#include<vector>
using namespace std;
void display(vector<int>ans){
    cout<<"Your New Array Is : ";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
void remove(vector<int>ans , vector<int>original , int target , int idx){
    if(idx == original.size()){
        display(ans);
        return;
    }
    int element = original[idx];
    if(element != target) {
        ans.push_back(original[idx]);
        remove(ans,original,target,idx+1);
    }
    else{
        remove(ans,original,target,idx+1);
    }
}
int main(){
    int n;
    cout<<"Enter size of an Arry : ";
    cin>>n;
    vector<int>v(n);
    cout<<"Fill The Array : ";
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int m;
    cout<<"Enter element to remove in Array : ";
    cin>>m;

    vector<int>w;
    remove(w,v,m,0);
    
}