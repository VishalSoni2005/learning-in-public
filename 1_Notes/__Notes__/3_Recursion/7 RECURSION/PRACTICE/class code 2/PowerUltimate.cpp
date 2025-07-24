#include<iostream>
using namespace std;
int power(int a,int b){
    if(a==0 && b==0){
        cout<<"ERROR ";
        return 404;
    }
    if(b==1) return a;
    if(a==1) return 1;
    if(b==0) return 1;
    if(a==0) return 0;
    if(b%2==0){
        int ans = power(a,b/2);
        return  ans*ans;
    }
    if(b%2!=0){
        int ans = power(a,b/2);
        return  ans*ans*a;
    }
    
}
int main(){
    int a , b;
    cout<<"ENTER BASE : ";
    cin>>a;
    cout<<"ENTER EXPONENT : ";
    cin>>b;
    cout<<"SOLUTION : "<<power(a,b);

    }