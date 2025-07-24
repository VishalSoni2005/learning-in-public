#include<bits/stdc++.h>
using namespace std;
void hanoi(int n,char a, char b,char c){
    if(n==0) return; //Base case
    hanoi(n-1,a,c,b);
    cout<<a<<" -> "<<c<<endl;
    hanoi(n-1,b,a,c);

}
int main(){
    int n;
    cout<<"Enter no of disk present in Source(A) rod : ";
    cin>>n;
    hanoi(n,'A','B','C');
    //cout<<endl;
    cout<<"No of Ways are : "<<(pow(2,n)) - 1;
}