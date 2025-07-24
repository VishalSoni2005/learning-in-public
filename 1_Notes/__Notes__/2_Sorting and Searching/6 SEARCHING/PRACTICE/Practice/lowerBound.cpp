#include<iostream>
#include<vector>
using namespace std;
void Upperbound(vector<int>&v,int x){
    int n = v.size();
    int lo = 0;
    int hi = n-1;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(v[mid] == x) cout<<"Element is present at : "<<mid;
        else if(v[mid] > x) hi = mid - 1;
        else if(v[mid] < x) lo = mid + 1;
    }
    cout<<"Upper bound of entered element is : "<<hi+1;
}
int main(){
    int n;
    cout<<"Enter the size of the vector : ";
    cin>>n;
    vector<int>v(n);
    cout<<"Fill the vector : ";
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int target;
    cout<<"Target : ";
    cin>>target;
    Upperbound(v,target);
}