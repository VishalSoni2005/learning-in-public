#include<iostream>
using namespace std;
long long fibo(int a){
    if(a==1 || a==2) return 1;
    return fibo(a-1) + fibo(a-2);
}
int main(){
    cout << fibo(42);
}