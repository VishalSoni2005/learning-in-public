#include<bits/stdc++.h>
using namespace std;
int UsingChutiyoWalamethod(vector<int>&v){
    int n = v.size();
    int idx = -1;
    for(int i=1;i<n-1;i++){
        if(v[i] > v[i-1] && v[i] > v[i+1]){
            idx = i;
            break;
        }
    }
    cout<< idx;
}
int UsingBinarySearch(vector<int>&v){
    int n = v.size();
    int idx = -1;
    int lo = 0;
    int hi = n-1;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(v[mid] > v[mid-1] && v[mid] > v[mid+1]){
            idx = mid;
            break;
        }
        else if(v[mid] < v[mid-1]) hi = mid - 1;
        else if(v[mid] < v[mid+1]) lo = mid + 1;
    }
    cout<< idx;
}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    cout<<"Fill the arrray : ";
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    //UsingChutiyoWalamethod(v);
    UsingBinarySearch(v);
}