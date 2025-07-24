#include<iostream>
#include<string>
using namespace std;
void usingRec(string ans , string original){
    if(original.length() == 0){
        cout<<"String after removal : "<<ans;
        return;
    }
    char ch = original[0];
    if(ch == 'a'){
        usingRec(ans,original.substr(1));
    }
    else{
        usingRec(ans + ch , original.substr(1));
    }
}
int main(){
    string str;
    cout<<"Enter your string : ";
    getline(cin , str);
    usingRec("" , str);
}