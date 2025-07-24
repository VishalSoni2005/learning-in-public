#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    int l = s.size();
    int count=0;
    for(int i=0;i<l;i++){
        if(l==1){
            break;
        }
        //from be 
        if(i==0){
            if(s[i] != s[i+1]) count++;
        }
        else if(i==l-1){
            if(s[i] != s[i-1]) count++;
        }
        else if(s[i] != s[i+1]) count++;
    }
    cout<<count;

}