//NOTE IN THIS QUESTION INPUT NOT CONTAIN A STRING HAVING DUBLICATE CHARACTER IE {aab}
#include<iostream>
#include<vector>
#include<string>
using namespace std;
void subset1(string ans , string original){
    if(original == ""){
        cout<<ans<<" ";
        return; 
    }
    char ch = original[0];
    subset1(ans + ch,original.substr(1));
    subset1(ans,original.substr(1));
    
}
void subset2(string ans , string original , int idx){
    if(idx == original.length()){
        cout<<ans<<" ";
        return; 
    }
    char ch = original[idx];
    subset2(ans+ch,original,idx+1);
    subset2(ans,original,idx+1);
}
void subset3(string ans , string original ,int idx , vector<string>&v){
    if(idx == original.length()){
        v.push_back(ans);
        cout<<ans<<" ";
        return;
    }
    char ch = original[idx];
    subset3(ans+ch,original,idx+1,v);
    subset3(ans,original,idx+1,v);

}
int main(){
    string str;
    cout<<"Enter your string without using space : ";
    cin>>str;
    // //subset1("" , str);
    // subset2("" , str , 0);
    vector<string>v;
     subset3("" , str , 0 , v);
}