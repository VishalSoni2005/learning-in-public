#include <iostream>
#include <string>
using namespace std;
int main(){
    string s = "vishalsoni";
    //
    int i=0;
    int count=0;
    while(s[i]!='\n'){
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') 
        count++;
        i++;
    }
    cout<<count;
}