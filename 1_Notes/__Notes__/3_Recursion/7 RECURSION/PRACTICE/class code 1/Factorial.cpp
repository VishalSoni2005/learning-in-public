#include<iostream>
using namespace std;
int fact(int n ){ //Simple code without recursion
    int f = 1;
    for(int i=2;i<=n;i++){
        f *= i;
    }
    return f;
}
int main(){
    int n;
    cout<<"Enter a no. you want to take factorial : ";
    cin>>n;
    cout<<fact(n);
    
}