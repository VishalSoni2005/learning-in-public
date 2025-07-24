#include<iostream>
using namespace std;
bool twoPower(int n){
    if(n==1) { //BASE CALL
        return true;
    }
    if(n%2==0){ 
        return twoPower(n/2);//recursive call
    }
    return false;
}
int main(){
    int n;
    cout<<"Enter a number : ";
    cin>>n;
    if(twoPower(n)){ //if given condition is true
        cout<<"YES"<<endl;
    }
    else{ //if given condition is false
        cout<<"Nope";
    }
}