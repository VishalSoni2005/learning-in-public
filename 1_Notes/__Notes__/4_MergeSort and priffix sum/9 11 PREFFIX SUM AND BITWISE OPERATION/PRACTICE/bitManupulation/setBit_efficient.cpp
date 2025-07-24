#include<bits/stdc++.h>
using namespace std;
int countSetBit(int n){
    int count = 0;
    while(n>0){
        count ++;
        n = ( n & (n-1));
    }
    return count;
}
string D2B(string &ans , int n){
    while( n > 0 ) {
        if(n%2==0) ans = "0" + ans;
        else ans = "1" + ans;
        n /= 2;
    }
    return ans;
}
int main(){
    int n;
    cout<<"Give A Decimal No . : ";
    cin>>n; 
    string ans = "";
    cout<<"Its binary represent is : "<<D2B(ans , n)<<endl;
    cout<<"By using inBuilt function : "<<__builtin_popcount(n);
    cout<<endl;
    cout<<"THROUGH BRAIN KERNIGLS ALGORITHM -> "<<countSetBit(n);
}