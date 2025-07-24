#include<bits/stdc++.h>
using namespace std;
 void removeChar(string original , string ans, int idx,char ch){
    if(idx == original.length()) {
        cout<<ans;
        return;
    }
    if(original[idx] != ch){
        ans.push_back(original[idx]);
        removeChar(original,ans,idx+1,ch);
    }
    else removeChar(original,ans,idx+1,ch); 
 }
int main(){
    string str;
    cout<<"Enter string : ";
    cin>>str;
    char ch;
    cout<<"Enter a char You wanna remove : ";
    cin>>ch;

    removeChar(str,"",0,ch);
}