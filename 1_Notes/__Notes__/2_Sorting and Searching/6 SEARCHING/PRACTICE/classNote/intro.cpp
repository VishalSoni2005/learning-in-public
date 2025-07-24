#include<bits/stdc++.h>
using namespace std;
void binarysearch(vector<int>v,int m){
    //BINARY SEARCH -> ARRAY MUST BE SORTED
    int n = v.size();
    int lo = 0;
    int hi = n-1;
    bool flag = false;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(v[mid]==m){
            cout<<"INDEX IS : "<<mid;
            flag = true;
        }
        else if(v[mid]>m) hi = mid -1;
        else lo = mid + 1;
    }
    if(flag == false) cout<<"404 Element not found";
}
int main(){
    int n;
    cout<<"Enter the size of vector : ";
    cin>>n;
    int v[n];
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int m;
    cout<<"Enter the target element : ";
    cin>>m;
    
    //BINARY SEARCHING
    int lo=0;
    int hi=n-1;
    while(lo<hi){
        int mid = lo + (hi-lo)/2;
        if(v[mid]==m) cout<<mid;
        else if(v[mid]>m) hi = mid -1;
        else if(v[mid]<m) lo = mid + 1;
    }   
}