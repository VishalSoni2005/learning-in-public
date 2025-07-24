#include<iostream>
using namespace std;
int power(int a,int b){
    if(b==0) return 1;
    return a*power(a,b-1);

}
int main(){
    int n;
    cout<<"Enter base : ";
    cin>>n;
    int m;
    cout<<"Enter argument : ";
    cin>>m;
    cout<<"Base Raised to power Exponent is : ";
    cout<<power(n,m);

}