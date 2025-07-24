//LOVELY CODE 
#include <iostream>
#include<vector>
using namespace std;
void firstOccure(vector<int>&v , int x){
    int n= v.size();
    int lo = 0;
    int hi = n-1;
    bool flag = false;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(v[mid] ==x){
            if(v[mid] == x && v[mid-1] != x){
            cout<<"First Occurance is : "<<mid;
            flag = true;
            break;
        }
            else if(v[mid] == v[mid+1] && v[mid] == v[mid-1]) hi = mid -1;
            else if(v[mid] == v[mid-1] && v[mid+1]!=x) hi = mid -1;
        }
        else if(v[mid] > x) hi = mid -1;
        else if(v[mid] < x) lo = mid +1;
    }
    if(flag == false) cout<<"404 ERROR";
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
    firstOccure(v,target);
}


       