#include<iostream>
using namespace std;
void display(int n){
    if(n==0) return;
    cout<<"Good Morning"<<endl;
    display(n-1);
}
int main(){
    int n;
    cout<<"Enter no. of times you want to grete yourself : ";
    cin>>n;
    display(n);
}