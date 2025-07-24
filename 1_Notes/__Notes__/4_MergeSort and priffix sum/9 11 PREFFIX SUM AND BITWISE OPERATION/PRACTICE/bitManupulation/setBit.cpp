#include<bits/stdc++.h>
using namespace std;
int setBit(string &ans){
    int n = ans.length();
    int count = 0;
    for(int i=0;i<n;i++){
        if(ans[i] == '1') count ++;
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
    cout<<"Give A Decimal No . :";
    cin>>n; 
    string ans = "";
    cout<<"Its binary represent is : "<<D2B(ans , n)<<endl;
    cout<<"SetBit is : "<<setBit(ans)<<endl;
    cout<<"By using inBuilt function : "<<__builtin_popcount(n);
}