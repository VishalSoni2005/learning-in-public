#include<Iostream>
#include<string>
using namespace std;
void skipAChar(string original, char ch , string ans , int idx){
    if(idx == original.length()){
        cout<<ans;
        return;
    }
    char ele = original[idx];
    if(ele != ch) skipAChar(original,ch,ans+ele,idx+1);
    else skipAChar(original,ch,ans,idx+1);
}
int main(){
    cout<<"Enter your String : ";
    string str;
    getline(cin,str);
    char ch;
    cout<<"Enter the character you wanna remove : ";
    cin>>ch;
    cout<<"String after removal of "<<ch<<" is : ";
    skipAChar(str,ch,"",0);
}