#include<bits/stdc++.h>
using namespace std;
void subset(string original , int size , string ans , int idx){
    if(size == 0){
        cout<<ans<<endl;
        return;
    }
    subset(original,size-1,ans+original[idx],idx+1);
    subset(original,size-1,ans,idx+1);  

}
int main(){
    string str;
    cout<<"Enter original string : ";
    cin>>str;
    int n = str.length();
    subset(str,n,"",0);
}