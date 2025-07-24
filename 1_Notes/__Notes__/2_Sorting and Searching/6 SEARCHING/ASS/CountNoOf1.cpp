#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"Size of vector : ";
    cin>>n;
    vector<int>v(n);
    cout<<"Fill the vector with sorted 0's and 1's: ";
    for(int i=0;i<n;i++){
        cin>>v[i];
    } 

    //BINARY SEARCHING -> first find index of first occurance
    int lo = 0;
    int hi = n-1;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(v[mid]==1){
            if(v[mid-1]=1) hi = mid -1;
            else cout<<mid;
        }
        else if(v[mid] = 0) lo = mid +1;
        else hi = mid -1;
    }
    
}