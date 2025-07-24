//NO OF SUBSET OF n ELEMENTS IS power(2,n;
#include<iostream>
#include<string>
using namespace std;
void printSubstirng(string original, string ans , int idx){
    if(idx == original.length()){
        cout<<ans<<endl;
        return;
    }
    char ch = original[idx];
    printSubstirng(original,ans+ch,idx+1);
    printSubstirng(original,ans,idx+1);
}
int main(){
    cout<<"Enter a String hsving unique element : ";
    string str; 
    cin>>str;
    printSubstirng(str,"",0);
    
}