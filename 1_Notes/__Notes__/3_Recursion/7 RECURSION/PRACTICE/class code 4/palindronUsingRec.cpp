#include<bits/stdc++.h>
using namespace std;
bool palindron(string s, int i,int j){
    if(i>j) return true;
    if(s[i] != s[j]) return false;
    else return palindron(s,i+1,j-1);
}
int main(){
    cout<<"Enter the String : ";
    string str;
    cin>>str;
    cout<<palindron(str,0,str.length()-1);
}