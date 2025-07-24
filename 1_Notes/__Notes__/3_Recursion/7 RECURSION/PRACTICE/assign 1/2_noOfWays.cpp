#include<iostream>
using namespace std;
int noOfWays(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    if(n==2) return 2;
    if(n==3) return 4;

    return noOfWays(n-1) + noOfWays(n-2) + noOfWays(n-3);
}
int main(){
    int n;
    cout<<"Enter number of stairs : ";
    cin>>n;
    cout<<noOfWays(n);
}