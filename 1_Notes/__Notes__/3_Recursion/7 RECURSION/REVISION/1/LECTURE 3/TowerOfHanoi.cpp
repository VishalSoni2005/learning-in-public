#include <bits/stdc++.h>
using namespace std;
void hanoi(int n,char a, char b, char c){
    if(n==1) return;
    hanoi(n-1,a,c,b); //ABHI C HELPING HAI
    cout<<a<<" -> "<<c<<endl;
    hanoi(n-1,b,a,c);

}
int main(){
    int n;
    cout<<"NO of disc present on A : ";
    cin>>n;
    hanoi(n,'a','b','c');
}