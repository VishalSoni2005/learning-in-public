#include<iostream>
using namespace std;
int ans=0;
int pow(int n , int m){
    if(m==1) return n;
    if(m%2==0){
        ans = pow(n,m/2) * pow(n,m/2);
    }
    if(m%2!=0){
        ans= pow(n,m/2) * pow(n,m/2) * n;
    }
}
int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    pow(n,m);
    cout<<ans;
}