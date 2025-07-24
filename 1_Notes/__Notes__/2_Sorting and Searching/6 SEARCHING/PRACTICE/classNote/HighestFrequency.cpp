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

    //SEARCHING
    int lo = 0;
    int hi = n-1;
    bool flag = false;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(v[mid]==m){
            if(v[mid-1]!=m){ //ISKA MATLAB YAHI MERA FIRST OCCURANCE HAI
                flag = true;
                cout<<mid+1;
                break;
            }
            else{   // ISKA MATLAB LEFT ME ELE HAI
                hi = mid -1;
            }
        }
        else if(v[mid]<m) lo = mid+1;
        else hi = mid - 1;
    }
    if(flag == false) cout<<-1;
    
}