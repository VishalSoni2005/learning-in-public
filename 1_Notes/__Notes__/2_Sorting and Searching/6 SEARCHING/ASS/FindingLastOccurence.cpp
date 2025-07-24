#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"Size of vector : ";
    cin>>n;
    vector<int>v(n);
    cout<<"Fill the vector : ";
    for(int i=0;i<n;i++){
        cin>>v[i];
    } 
    int x;
    cout<<"Enter the target : ";
    cin>>x;

    //searching -> array must be sorted
    int lo = 0;
    int hi = n-1;
    bool flag = false;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(v[mid] == x){
            if(v[mid+1] == x){
                 lo = mid + 1 ;
            }
            else{
                cout<<"index is : "<<mid+1;
                flag = true;
                break;
            }
        }
        else if(v[mid]>x) hi = mid -1;
        else lo = mid +1;
    }
    if(flag == false)cout<<-1;
}