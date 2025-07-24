#include<iostream>
using namespace std;
void print(int n){
    if(n==0) return;
    cout<<"I'm the best"<<endl;
    print(n-1);
}
int main(){
    int n = 6;
    print(n);
}