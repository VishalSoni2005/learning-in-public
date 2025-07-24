#include<iostream>
#include <string>
#include<algorithm>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    cout<<s<<endl;
    int len = s.size();
    reverse(s.begin(),s.begin()+len/2);  //we have to write till extra index form which we waan to reverse  
    cout<<s;  
}