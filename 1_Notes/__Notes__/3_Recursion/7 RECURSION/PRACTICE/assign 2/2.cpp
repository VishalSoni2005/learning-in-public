//Print the index of given target
#include<bits/stdc++.h>
using namespace std;
int targetIndex(vector<int>&v , int target , int idx){
    if(v[idx] == target){
        cout<<"index is : "<<idx;
        return idx;
    }
    else {
        cout<<-1;
        return -1;
    }
    targetIndex(v,target,idx+1);
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
    int target;
    cout<<"Enter the target : ";
    cin>>target;
    targetIndex(v,target,0);
}