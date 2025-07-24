#include<iostream>
#include<string>
using namespace std;
void usingLoop(string str , string s){
    for(int i=0;i<str.length();i++){
        if(str[i] != 'a' && str[i] != 'A') s.push_back(str[i]);
    }
    cout<<s;
}
int main(){
    string str;
    cout<<"Enter your string : ";
    getline(cin , str);
    string s = "";
    usingLoop(str,s);

}