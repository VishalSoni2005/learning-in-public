//STRING CAN HAVE DUBLICATE CHARACTER LIKE "aba" BUT SUBSET MUST NOT HAVe DUBLICATE CHAR
#include<bits/stdc++.h>
using namespace std;
void storeSubset(string original, string ans , bool flag , vector<string>v){
    if(original==""){
        v.push_back(ans);
        return;
    }
    char ch = original[0];
    if(original.length() == 1){
        if(flag == true)storeSubset(original.substr(1),ans+ch,true,v);
        storeSubset(original.substr(1),ans,true,v);
        return;
    }
    char dh = original[1];
    if(ch==dh){//iska matlab dublicate hai toh left call matt lagao
        if(flag == true) storeSubset(original.substr(1),ans+ch,true,v);
        storeSubset(original.substr(1),ans,true,v);
    }
    else{ //no dublicate element is present
        if(flag == true) storeSubset(original.substr(1),ans+ch,true,v);
        storeSubset(original.substr(1),ans,true,v);
    }
}
int main(){
    string str;
    cout<<"Enter original string : ";
    cin>>str;
    sort(str.begin() , str.end());
    vector<string>v;
    storeSubset(str,"",true,v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
}