#include<bits/stdc++.h>
using namespace std;
void print(string s , int n){
    if(s.length() == n){
        cout<<s<<endl;
        return;
    }
    print(s+'0',n);
    if(s=="") print(s+'1',n);
    else if(s[s.length()-1] == '0') print(s+'1',n);
    
}
int main(){
    int n;
    cout<<"Enter size of your binary string : ";
    cin>>n;
    print("",n);
}