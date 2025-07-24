#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of vector : ";
    cin>>n;
    vector<int>v(n);
    cout<<"Fill the vector"<<endl;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int m;
    cout<<"Enter the target element : ";
    cin>>m;

    //BINARY SEARCHING
    int lo=0;
    int hi=n-1;
    bool flag = false;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(v[mid]==m){
            flag = true;
            cout<<v[mid-1];
            break;
        }
        else if(v[mid]>m) hi = mid - 1;
        else if(v[mid]<m) lo = mid + 1;
    }
    if(flag==false) cout<<v[hi];
}