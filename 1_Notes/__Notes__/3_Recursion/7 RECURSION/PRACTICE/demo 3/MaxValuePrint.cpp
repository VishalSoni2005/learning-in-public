#include <iostream>
#include<climits>
#include <vector>
using namespace std;
void maxPrint(vector<int>&v,int n,int idx , int max){
    if(idx == n){
        cout<<max;
        return;
    }
    if(v[idx] > max) max = v[idx];
    maxPrint(v,n,idx+1,max);
}
int main(){
    int n;
    cout<<"Enter size : ";
    cin>>n;
    vector<int>v(n);
    cout<<"Fill the array : ";
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<"Your element sir : ";
    maxPrint(v,n,0,INT_MIN);
}