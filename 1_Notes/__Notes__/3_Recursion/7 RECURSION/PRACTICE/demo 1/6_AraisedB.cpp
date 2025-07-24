#include<iostream>
using namespace std;
int power(int a,int b){
    if(a==0 && b==0) {
        cout<<"SYNTAX ERROR ";
        return 0;
    }
    if(b==0) return 1;
    
    return a*power(a,b-1);
}
int main(){
    int a;
    cout<<"BASE : ";
    cin>>a;
    int b;
    cout<<"EXPONENT : ";
    cin>>b;
    cout<<"BASE RAISED TO EXPOONENT IS : ";
    cout<<power(a,b); 
    
}