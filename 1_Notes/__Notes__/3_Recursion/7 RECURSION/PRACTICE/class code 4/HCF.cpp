//HCF ( a,b ) = HCF( b%a,a )
#include<iostream>
using namespace std;
int hcfRec(int a , int b){
    if(a==0) return b;
    hcfRec(b%a , a);
}
int hcfLoop(int a , int b){
    for(int i=min(a , b); i>=2 ; i--){
        if(a%i==0 && b%i==0)  return i;
    }
    return 1;
}
int main(){
    int n;
    cout<<"Enter first number : ";
    cin>>n;
    int m;
    cout<<"Enter second number : ";
    cin>>m;
   // cout<<"HCF is : "<<hcfLoop(n,m);
    cout<<"HCF is : "<<hcfRec(n,m);
    
}