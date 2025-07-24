#include<iostream>
#include<string>
using namespace std;
void skipa(string ans , string original ,char ch , int idx){
    if(idx == original.length()){   //BASE CASE
        cout<<ans;
        return;
    }
    char ele = original[idx];
    if(ele != ch) skipa(ans+ele,original,ch,idx+1); //YE PAPPEND KAREGA
    else skipa(ans,original,ch,idx+1); //YE IDEX KA COUNT BADHANE KE LIYEA HAI
}
int main(){
    string str;
    cout<<"Enter a string : ";
    cin>>str;
    char ch;
    cout<<"Enter a character u wanna remove : ";
    cin>>ch;
    skipa("",str,ch,0);
}