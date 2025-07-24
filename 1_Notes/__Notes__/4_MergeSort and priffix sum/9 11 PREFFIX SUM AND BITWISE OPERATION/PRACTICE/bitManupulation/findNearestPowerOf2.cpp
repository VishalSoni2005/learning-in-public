#include<iostream>
using namespace std;
int main(){
    int x;
    cout<<"Enter A number : ";
    cin>>x;
    cout<<"Nearest is : ";
    int temp ;
    while(x!=0){
        temp = x;
        x = x & (x-1);
    }
    cout<<temp; 
}