#include<bits/stdc++.h>
using namespace std;
int maxxx(int n, vector<int>&v , int max,int idx){
    if(n == 0) return max;
    if(v[idx] > max) {
        max = v[idx];
        maxxx(n-1,v,max,idx+1);
    }
    else maxxx(n-1,v,max,idx+1);
}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<maxxx(n,v,INT_MIN,0);
}